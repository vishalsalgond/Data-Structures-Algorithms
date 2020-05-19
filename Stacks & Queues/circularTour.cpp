//https://practice.geeksforgeeks.org/problems/circular-tour/1

/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
int tour(petrolPump p[],int n)
{
   for(int i=0;i<n;i++){
       int curr=i,count=n,total=0,flag;
       while(count--){
           flag = 0;
           total += (p[curr].petrol - p[curr].distance);
           curr = (curr+1)%n;
           if(total < 0){
               flag = 1;
               break;
           }
       }
       if(flag == 0) return i;
   }
   return -1;
}

