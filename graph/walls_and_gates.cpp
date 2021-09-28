public class Solution {

    public class Pair{
        int x;
        int y;

        public Pair(int x, int y){
            this.x = x;
            this.y = y;
        }
    }

    public void wallsAndGates(int[][] rooms) {

        int[][] dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        boolean[][] visited = new boolean[rooms.length][rooms[0].length];
        Queue<Pair> queue = new LinkedList<Pair>();

        for(int i = 0; i < rooms.length; i++){
            for(int j = 0; j < rooms[0].length; j++){
                if(rooms[i][j] == 0){
                    queue.offer(new Pair(i, j));
                    visited[i][j] = true;
                }
            }
        }
        int level = 0;
        while(!queue.isEmpty()){
            int size = queue.size();
            level++;
            while(size-- > 0){
                Pair currPair = queue.poll();
                for(int d = 0; d < dir.length; d++){
                    int r = currPair.x + dir[d][0];
                    int c = currPair.y + dir[d][1];

                    if(r >= 0 && r < rooms.length && c >= 0 && c < rooms[0].length && rooms[r][c] == 2147483647){
                        if(!visited[r][c]){
                            rooms[r][c] = level;
                            queue.offer(new Pair(r, c));
                            visited[r][c] = true;
                        }
                    }
                } 
            }
        }
    }
}
