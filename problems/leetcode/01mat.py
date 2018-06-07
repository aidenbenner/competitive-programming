class Solution:
    def updateMatrix(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """
        out_mat = []

        for row in matrix:
            out_mat.append([])
            for col in row:
                out_mat[-1].append(-1)

        def fill(x,y):
            if x < 0 or y < 0 or y >= len(matrix) or x >= len(matrix[0]):
                return 100000000

            if matrix[y][x] == 0:
                out_mat[y][x] = 0
                return 0

            if out_mat[y][x] != -1:
                val = fill(x - 1, y)
                val = min(val, fill(x + 1, y))
                val = min(val, fill(x, y - 1))
                val = min(val, fill(x, y + 1))
                if val + 1 < out_mat[y][x]:
                    out_mat[y][x] = val + 1
                    fill(x - 1, y)
                    fill(x + 1, y)
                    fill(x, y - 1)
                    fill(x, y + 1)
                return out_mat[y][x]

            out_mat[y][x] = 100000000

            val = fill(x - 1, y)
            val = min(val, fill(x + 1, y))
            val = min(val, fill(x, y - 1))
            val = min(val, fill(x, y + 1))

            fill()

            out_mat[y][x] = 1 + val
            return 1 + val

        y = 0
        for row in matrix:
            x = 0
            for col in row:
                fill(x,y)
                x += 1
            y += 1
        return out_mat


s = Solution()
mat = [[0,0,0],[0,1,0],[1,1,1]]
y = len(mat)
z = len(mat[0])
s.updateMatrix(mat)
