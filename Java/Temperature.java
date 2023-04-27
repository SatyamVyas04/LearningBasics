public class Temperature{
    public static void main(String[] args){
        String[] cities = {"MUM", "DEL", "IXJ", "BLR", "JSA", "IXC", "NAG", "SUR", "AGR", "THA"};
        int [][] temps = {
                {30, 32, 31, 29, 28, 30, 29, 31, 33, 32, 33, 35, 32, 34, 31, 30, 30, 29, 29, 28, 30, 28, 30, 32, 34, 35, 34, 35, 36, 34, 33},
                {28, 30, 29, 27, 26, 28, 27, 29, 31, 30, 31, 33, 30, 32, 29, 28, 28, 27, 27, 26, 28, 26, 28, 30, 32, 33, 32, 33, 34, 32, 31},
                {31, 33, 32, 30, 29, 31, 30, 32, 34, 33, 34, 36, 33, 35, 32, 31, 31, 30, 30, 29, 31, 29, 31, 33, 35, 36, 35, 36, 37, 35, 34},
                {26, 28, 27, 25, 24, 26, 25, 27, 29, 28, 29, 31, 28, 30, 27, 26, 26, 25, 25, 24, 26, 24, 26, 28, 30, 31, 30, 31, 32, 30, 29},
                {29, 31, 30, 28, 27, 29, 28, 30, 32, 31, 32, 34, 31, 33, 30, 29, 29, 28, 28, 27, 29, 27, 29, 31, 33, 34, 33, 34, 35, 33, 32},
                {32, 34, 33, 31, 30, 32, 31, 33, 35, 34, 35, 37, 34, 36, 33, 32, 32, 31, 31, 30, 32, 30, 32, 34, 36, 37, 36, 37, 41, 36, 35},
                {27, 29, 28, 26, 25, 27, 26, 28, 30, 29, 30, 32, 29, 31, 28, 27, 27, 26, 26, 25, 27, 25, 27, 29, 31, 32, 31, 32, 33, 31, 30},
                {30, 32, 31, 29, 28, 30, 29, 31, 33, 32, 33, 35, 32, 34, 31, 30, 30, 29, 31, 30, 32, 30, 32, 34, 36, 37, 36, 37, 38, 36, 35},
                {30, 32, 31, 29, 28, 30, 29, 31, 33, 32, 33, 35, 32, 34, 31, 30, 30, 05, 29, 28, 30, 28, 30, 32, 34, 35, 34, 35, 36, 34, 33},
                {28, 30, 29, 27, 26, 28, 27, 29, 31, 30, 31, 33, 30, 32, 29, 28, 28, 27, 27, 26, 28, 26, 28, 30, 32, 33, 32, 33, 34, 32, 31}
                };
                
        int lowest = 100;
        String lowestcity = "";
        int lowestdateindex = 0;
        
        int highest = 0;
        String highestcity = "";
        int highestdateindex = 0;
        
        for(int i = 0; i<10; i++){
            for(int j=0; j<31; j++){
                if(temps[i][j]<lowest){
                    lowest = temps[i][j];
                    lowestdateindex = j;
                    lowestcity = cities[i];
                }
                if(temps[i][j]>highest){
                    highest = temps[i][j];
                    highestdateindex = j;
                    highestcity = cities[i];
                }
            }
        }
        System.out.println("---- Temperature Report for January ----");
        System.out.println("> City with Highest Temperature: "+highestcity);
        System.out.println("> On Date: "+(highestdateindex+1));
        System.out.println("> Temperature: "+highest);
        System.out.println();
        System.out.println("> City with Lowest Temperature: "+lowestcity);
        System.out.println("> On Date: "+(lowestdateindex+1));
        System.out.println("> Temperature: "+lowest);        
    }
}
