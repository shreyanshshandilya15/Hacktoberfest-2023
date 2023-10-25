#Fractional knapsack problem
#
double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
           auto comp = [](Item a, Item b) {
            double s1 = (double)a.value / (double)a.weight;
            double s2 = (double)b.value / (double)b.weight;
            return s1 > s2;
        };
        sort(arr,arr + n,comp);
        int currweight=0;
        double finalvalue=0.0;
        
        for(int i=0;i<n;i++){
            if(currweight+arr[i].weight<=W){
                currweight+=arr[i].weight;
                finalvalue+=arr[i].value;
            }
            else{
                int remain=W-currweight;
                finalvalue+=(arr[i].value/(double)arr[i].weight)*(double)remain;
                break;
            }
        }
        return finalvalue;
        
    }
