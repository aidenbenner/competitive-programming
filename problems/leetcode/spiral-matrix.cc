class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> out;
            if (matrix.size() == 0) return out;
            print(0, matrix.size() - 1, 0, matrix[0].size() - 1, out, matrix, 0);
            return out;
        }

        void print(int sr, int er, int sc, int ec, vector<int> &out, vector<vector<int>>& matrix, int dir) {
            if (sr > er) return;
            if (sc > ec) return;

            // top left -> top right
            if (dir == 0) {
                for (int i = sc; i<=ec; i++) {
                    out.push_back(matrix[sr][i]);
                }
                print(sr + 1, er, sc, ec, out, matrix, 1);
            }
            else if(dir == 1) {
                for (int i = sr; i<=er; i++) {
                    out.push_back(matrix[i][ec]);
                }
                print(sr, er, sc, ec - 1, out, matrix, 2);
            }
            else if(dir == 2) {
                for (int i = ec; i>=sc; i--) {
                    out.push_back(matrix[er][i]);
                }
                print(sr, er - 1, sc, ec, out, matrix, 3);
            }
            else {
                for (int i = er; i>=sr; i--) {
                    out.push_back(matrix[i][sc]);
                }
                print(sr, er, sc + 1, ec, out, matrix, 0);
            }
        }
};
