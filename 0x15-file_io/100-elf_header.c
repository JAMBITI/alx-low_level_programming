#include <stdio.h>
#include <stdlib.h>
#include <elf.h>

/**
 * main - Displays the information contained in the ELF header at the
 *        start of an ELF file.
 * @argc: Number of arguments passed into the program.
 * @argv: Array of arguments passed.
 * Return: 0 on success.
 */
int main(int argc, char **argv)
{
	FILE *file;
	Elf64_Ehdr header;

	if (argc != 2 || argv[1] == NULL)
	{
	fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
	exit(1);
	}

	file = fopen(argv[1], "rb");
	if (file == NULL)
	{
	fprintf(stderr, "Error: Cannot read file %s\n", argv[1]);
	exit(1);
	}

	fread(&header, sizeof(Elf64_Ehdr), 1, file);

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
	printf("%02x ", header.e_ident[i]);
	printf("\n");

	printf("  Class:                             ");
	switch (header.e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
	printf("none\n");
	break;
	case ELFCLASS32:
	printf("ELF32\n");
	break;
	case ELFCLASS64:
	printf("ELF64\n");
	break;
	default:
	printf("<unknown: %x>\n", header.e_ident[EI_CLASS]);
}

	printf("  Data:                              ");
	switch (header.e_ident[EI_DATA])
	{
	case ELFDATANONE:
	printf("none\n");
	break;
	case ELFDATA2LSB:
	printf("2's complement, little endian\n");
	break;
	case ELFDATA2MSB:
	printf("2's complement, big endian\n");
	break;
	default:
	printf("<unknown: %x>\n", header.e_ident[EI_DATA]);
	}

	printf("  Version:                           %d", header.e_ident[EI_VERSION]);
	switch (header.e_ident[EI_VERSION])
{
	case EV_NONE:
		printf(" (invalid)\n");
		break;
	case EV_CURRENT:
	printf(" (current)\n");
	break;
	default:
	printf("\n");
	break;
	}

	printf("  OS/ABI:                            ");
	switch (header.e_ident[EI_OSABI])
	{
	case ELFOSABI_SYSV:
	printf("UNIX - System V\n");
	break;
	case ELFOSABI_HPUX:
	printf("UNIX - HP-UX\n");
	break;
	case ELFOSABI_NETBSD:
	printf("UNIX - NetBSD\n");
	break;
	case ELFOSABI_LINUX:
	printf("UNIX - Linux\n");
	break;
	case ELFOSABI_SOLARIS:
	printf("UNIX - Solaris\n");
	break;
	case ELFOSABI_IRIX:
	printf("UNIX - IRIX\n");
	break;
	case ELFOSABI_FREEBSD:
	printf("UNIX - FreeBSD\n");
	break;
	case ELFOSABI_TRU64:
	printf("UNIX - TRU64\n");
	break;
	case ELFOSABI_ARM:
	printf("ARM\n");
	break;
	case ELFOSABI_STANDALONE:
	printf("Standalone App\n");
	break;
	default:
	printf("<unknown: %x>\n", header.e_ident[EI_OSABI]);
	}

	printf("  ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);

	printf("  Type:                              ");
	switch (header.e_type)
	{
	case ET_NONE:
	printf("NONE (None)\n");
	break;
	case ET_REL:
	printf("REL (Relocatable file)\n");
	break;
	case ET_EXEC:
	printf("EXEC (Executable file)\n");
	break;
	case ET_DYN:
	printf("DYN (Shared object file)\n");
	break;
	case ET_CORE:
	printf("CORE (Core file)\n");
	break;
	default:
	printf("<unknown: %x>\n", header.e_type);
	}

	printf("  Entry point address:               %#lx\n", header.e_entry);

	fclose(file);
	return (0);
}
