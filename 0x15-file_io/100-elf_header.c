#include <stdio.h>
#include <elf.h>

void print_elf_header(Elf64_Ehdr h);

void print_magic(Elf64_Ehdr h)
{
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
		printf("%2.2x%s", h.e_ident[i], i == EI_NIDENT - 1 ? "\n" : " ");
}

void print_class(Elf64_Ehdr h)
{
	printf("  Class:   ");
	switch (h.e_ident[EI_CLASS])
	{
		case ELFCLASS64:
			printf("ELF64");
			break;
		case ELFCLASS32:
			printf("ELF32");
			break;
		case ELFCLASSNONE:
			printf("none");
			break;
	}
	printf("\n");
}

void print_data(Elf64_Ehdr h)
{
	printf("  Data:    ");
	switch (h.e_ident[EI_DATA])
	{
		case ELFDATA2MSB:
			printf("2's complement, big endian");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian");
			break;
		case ELFDATANONE:
			printf("none");
			break;
	}
	printf("\n");
}


void print_version(Elf64_Ehdr h)
{
	printf("  Version: %d", h.e_ident[EI_VERSION]);
	switch (h.e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)");
			break;
		case EV_NONE:
			break;
	}
	printf("\n");
}

void print_osabi(Elf64_Ehdr h)
{
	printf("  OS/ABI:  ");
	switch (h.e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux");
			break;
		case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris");
		break;
		case ELFOSABI_AIX:
		printf("UNIX - AIX");
		break;
		case ELFOSABI_IRIX:
		printf("UNIX - IRIX");
		break;
		case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD");
		break;
		case ELFOSABI_TRU64:
		printf("UNIX - TRU64");
		break;
		default:
		printf("<unknown: %x>", h.e_ident[EI_OSABI]);
		break;
	}
	printf("\n");
}

void print_abiversion(Elf64_Ehdr h)
{
	printf("  ABI Version: %d\n", h.e_ident[EI_ABIVERSION]);
}

void print_type(Elf64_Ehdr h)
{
	printf("  Type:    ");
	char *p = (char *)&h.e_type;
	int i = h.e_ident[EI_DATA] == ELFDATA2MSB ? 1 : 0;

	switch (p[i])
	{
		case ET_NONE:
			printf("NONE (None)");
			break;
		case ET_REL:
			printf("REL (Relocatable file)");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)");
			break;
		case ET_CORE:
			printf("CORE (Core file)");
			break;
		default:
			printf("<unknown>: %x", p[i]);
			break;
	}
	printf("\n");
}

void print_entry(Elf64_Ehdr h)
{
	printf("  Entry point address: 0x");
	unsigned char *p = (unsigned char *)&h.e_entry;
	int i = h.e_ident[EI_DATA] == ELFDATA2MSB ? 0 : 7;

	while (!p[i])
		i = h.e_ident[EI_DATA] == ELFDATA2MSB ? i + 1 : i - 1;
	for (; i >= 0 && i <= 7; i = h.e_ident[EI_DATA] == ELFDATA2MSB ? i + 1 : i - 1)
		printf("%02x", p[i]);
	printf("\n");
}

void print_elf_header(Elf64_Ehdr h)
{
	printf("ELF Header:\n");
	print_magic(h);
	print_class(h);
	print_data(h);
	print_version(h);
	print_osabi(h);
	print_abiversion(h);
	print_type(h);
	print_entry(h);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <elf_file>\n", argv[0]);
		return (1);
	}

	FILE *file = fopen(argv[1], "rb");

	if (!file)
	{
		fprintf(stderr, "Error: Cannot open file: %s\n", argv[1]);
		return (1);
	}

	Elf64_Ehdr header;

	if (fread(&header, sizeof(header), 1, file) != 1)
	{
		fprintf(stderr, "Error: Cannot read from file: %s\n", argv[1]);
		fclose(file);
		return (1);
	}

	if (header.e_ident[0] != 0x7f || header.e_ident[1] != 'E' || header.e_ident[2] != 'L' || header.e_ident[3] != 'F')
	{
		fprintf(stderr, "Error: Not an ELF file: %s\n", argv[1]);
		fclose(file);
		return (1);
	}

	print_elf_header(header);

	fclose(file);
	return (0);
}
