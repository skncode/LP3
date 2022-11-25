#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int value;
		int weight;
};

bool compare(Node a, Node b){
	double r1 = (double)a.value/(double)a.weight;
	double r2 = (double)b.value/(double)b.weight;
	
	return r1>r2;
}


double knapsack(Node arr[],int w, int n){
	sort(arr,arr+n,compare);
	
	int current_w = 0;
	double max_value = 0.0;
	for(int i=0;i<n;i++){
		if(current_w+arr[i].weight <= w){
			max_value = max_value + arr[i].value;
			current_w = current_w + arr[i].weight;
		}else{
			double remain = w - current_w;
			
			max_value = max_value + ((double)arr[i].value/(double)arr[i].weight)*(double)remain;
			break;
		}
	}
	return max_value;
}

int main(){
	
	Node arr[3] ={{21,10},{39,7},{17,3}};
	cout<<knapsack(arr,12,3);
	return 0;
}