class Solution:
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """

        adjList = [[] for x in range(numCourses)]

        for x in prerequisites:
            print(str(x[0]) + " " + str(x[1]))
            adjList[x[0]].append(x[1])

        z = adjList

        visited = [False] * numCourses

        topStack = []

        stack = []
        def DFS(node):
            if node in stack:
                return -1
            if visited[node]:
                return 0
            stack.append(node)

            print(adjList[node])
            for x in adjList[node]:
                if DFS(x) == -1:
                    return -1

            visited[node] = True
            stack.pop()
            return 0

        for x in range(numCourses):
            if DFS(x) == -1:
                return False
        return True


s = Solution()
x = s.canFinish(3, [[0,1],[1,2]])
x = s.canFinish(2, [[0,1],[1,0]])
