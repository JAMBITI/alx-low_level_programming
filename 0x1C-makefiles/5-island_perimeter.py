#!/usr/bin/python3
"""Defines an island perimeter measuring function."""


def island_perimeter(grid):
    def dfs(i, j):
        nonlocal edges
        if i < 0 or i >= len(grid) or j < 0 or j >= len(grid[0]) or grid[i][j] == 0:
            edges += 1
            return

        if grid[i][j] == -1:
            return

        grid[i][j] = -1  # Mark the cell as visited

        # Explore in all four directions
        dfs(i + 1, j)
        dfs(i - 1, j)
        dfs(i, j + 1)
        dfs(i, j - 1)

    edges = 0
    for i in range(len(grid)):
        for j in range(len(grid[0]):
            if grid[i][j] == 1:
                dfs(i, j)

return edges
