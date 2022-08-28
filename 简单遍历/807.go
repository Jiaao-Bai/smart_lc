func maxIncreaseKeepingSkyline(grid [][]int) int {
	var (
		n              int   = len(grid)
		max_per_column []int = make([]int, n)
		max_per_row    []int = make([]int, n)
		ret            int   = 0
	)

	for i, row := range grid {
		for j, h := range row {
			if h > max_per_row[i] {
				max_per_row[i] = h
			}
			if h > max_per_column[j] {
				max_per_column[j] = h
			}
		}
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			var max_height int
			if max_per_row[i] < max_per_column[j] {
				max_height = max_per_row[i]
			} else {
				max_height = max_per_column[j]
			}
			ret += max_height - grid[i][j]
		}
	}
	return ret
}