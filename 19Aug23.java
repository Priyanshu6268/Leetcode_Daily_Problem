//.   https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/description/
class Solution {
    public List<List<Integer>> findCriticalAndPseudoCriticalEdges(int n, int[][] edges) {
        Map<int[], Integer> edgeIndexMap = new HashMap();
        for(int i = 0; i <edges.length; i++)
            edgeIndexMap.put(edges[i], i);
        List<Integer> criticalEdges = new ArrayList();
        List<Integer> pseudoCriticalEdges = new ArrayList();
        Arrays.sort(edges, (a,b)->a[2]-b[2]);
        int minCost = MST(n, edges, null, null);
        for(int[] edge:edges){
            int excludeCost = MST(n, edges, null, edge);
            if (excludeCost>minCost)
                criticalEdges.add(edgeIndexMap.get(edge));
            else{
                int includeCost = MST(n, edges, edge, null);
                if (includeCost == minCost)
                    pseudoCriticalEdges.add(edgeIndexMap.get(edge));
            }
        }
        return Arrays.asList(criticalEdges, pseudoCriticalEdges);
    }
    private int MST(int n, int[][] edges, int[] include, int[] exclude){
        int cost=0;
        UnionFind uf = new UnionFind(n);
        if (include!=null){
            uf.union(include[0], include[1]);
            cost+=include[2];
        }
        for(int[] edge: edges)
            if (edge!=exclude && (uf.union(edge[0], edge[1])))
                cost+=edge[2];
        return (uf.components==1)? cost: Integer.MAX_VALUE;
    }
}
class UnionFind{
    int components;
    int[] root;
    UnionFind(int n){
        components =n;
        root = new int[n];
        for(int i = 0; i<n; i++)
            root[i]=i;
    }
    int find(int v){
        if (root[v]==v)
            return v;
        return find(root[v]);
    }
    boolean union(int v1, int v2){
        int ar1 = find(v1);
        int ar2 = find(v2);
        if (ar1==ar2)
            return false;
        root[ar1]=ar2;
        components--;
        return true;
    }
}
