class Solution:
    def allPathsSourceTarget(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: List[List[int]]
        """

        def DFS(curr, dest):
            if curr == dest:
                return [[dest]]

            out = []
            for x in graph[curr]:
                paths = DFS(x, dest)

                for p in paths:
                    tmp = [curr]
                    tmp.extend(p)
                    out.append(tmp)

            return out

        return DFS(0, len(graph) - 1)

