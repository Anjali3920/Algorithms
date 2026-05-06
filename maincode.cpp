# insertion sort
#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter size: ";
    cin>>n;

    int arr[n];

    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    for(int i=1;i<n;i++)
    {
        int key=arr[i];
        int j=i-1;

        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }

        arr[j+1]=key;
    }

    cout<<"Sorted array: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}




# mergesort
#include<iostream>
using namespace std;

void merge(int arr[],int l,int m,int r)
{
    int n1=m-l+1;
    int n2=r-m;

    int L[n1],R[n2];

    for(int i=0;i<n1;i++)
        L[i]=arr[l+i];

    for(int j=0;j<n2;j++)
        R[j]=arr[m+1+j];

    int i=0,j=0,k=l;

    while(i<n1 && j<n2)
    {
        if(L[i]<R[j])
            arr[k++]=L[i++];
        else
            arr[k++]=R[j++];
    }

    while(i<n1)
        arr[k++]=L[i++];

    while(j<n2)
        arr[k++]=R[j++];
}

void mergeSort(int arr[],int l,int r)
{
    if(l<r)
    {
        int m=(l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    mergeSort(arr,0,n-1);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}





#heapsort
#include<iostream>
using namespace std;

void heapify(int arr[],int n,int i)
{
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;

    if(l<n && arr[l]>arr[largest])
        largest=l;

    if(r<n && arr[r]>arr[largest])
        largest=r;

    if(largest!=i)
    {
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[],int n)
{
    for(int i=n/2-1;i>=0;i--)
        heapify(arr,n,i);

    for(int i=n-1;i>0;i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    heapSort(arr,n);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}


#quicksort
#include<iostream>
using namespace std;

int partition(int arr[],int low,int high)
{
    int pivot=arr[high];
    int i=low-1;

    for(int j=low;j<high;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[i+1],arr[high]);
    return i+1;
}

void quickSort(int arr[],int low,int high)
{
    if(low<high)
    {
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    quickSort(arr,0,n-1);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}




#strassen matrix multiplication
#include<iostream>
using namespace std;

int main()
{
    int a[2][2],b[2][2],c[2][2];

    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            cin>>a[i][j];

    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            cin>>b[i][j];

    int p1=(a[0][0]+a[1][1])*(b[0][0]+b[1][1]);
    int p2=(a[1][0]+a[1][1])*b[0][0];
    int p3=a[0][0]*(b[0][1]-b[1][1]);
    int p4=a[1][1]*(b[1][0]-b[0][0]);
    int p5=(a[0][0]+a[0][1])*b[1][1];
    int p6=(a[1][0]-a[0][0])*(b[0][0]+b[0][1]);
    int p7=(a[0][1]-a[1][1])*(b[1][0]+b[1][1]);

    c[0][0]=p1+p4-p5+p7;
    c[0][1]=p3+p5;
    c[1][0]=p2+p4;
    c[1][1]=p1-p2+p3+p6;

    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
            cout<<c[i][j]<<" ";
        cout<<endl;
    }
}




#count sort
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int arr[n],max=0;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]>max)
            max=arr[i];
    }

    int count[max+1]={0};

    for(int i=0;i<n;i++)
        count[arr[i]]++;

    for(int i=0;i<=max;i++)
    {
        while(count[i]>0)
        {
            cout<<i<<" ";
            count[i]--;
        }
    }
}




#bfs
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int graph[10][10];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>graph[i][j];

    int visited[10]={0},queue[10],front=0,rear=0;

    queue[rear++]=0;
    visited[0]=1;

    while(front<rear)
    {
        int node=queue[front++];
        cout<<node<<" ";

        for(int i=0;i<n;i++)
        {
            if(graph[node][i]==1 && visited[i]==0)
            {
                queue[rear++]=i;
                visited[i]=1;
            }
        }
    }
}





# dfs
#include<iostream>
using namespace std;

int graph[10][10],visited[10],n;

void dfs(int node)
{
    cout<<node<<" ";
    visited[node]=1;

    for(int i=0;i<n;i++)
    {
        if(graph[node][i]==1 && visited[i]==0)
            dfs(i);
    }
}

int main()
{
    cin>>n;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>graph[i][j];

    dfs(0);
}





#prims algorithm
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int cost[10][10],visited[10]={0};
    int edges=0,mincost=0;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>cost[i][j];

    visited[0]=1;

    while(edges<n-1)
    {
        int min=999,a,b;

        for(int i=0;i<n;i++)
        {
            if(visited[i]==1)
            {
                for(int j=0;j<n;j++)
                {
                    if(!visited[j] && cost[i][j]<min)
                    {
                        min=cost[i][j];
                        a=i;
                        b=j;
                    }
                }
            }
        }

        cout<<a<<" - "<<b<<" = "<<min<<endl;
        mincost+=min;
        visited[b]=1;
        edges++;
    }

    cout<<"Minimum cost = "<<mincost;
}





#dijstrsa
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int cost[10][10],dist[10],visited[10]={0};

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>cost[i][j];

    for(int i=0;i<n;i++)
        dist[i]=cost[0][i];

    visited[0]=1;

    for(int count=1;count<n;count++)
    {
        int min=999,nextnode;

        for(int i=0;i<n;i++)
        {
            if(!visited[i] && dist[i]<min)
            {
                min=dist[i];
                nextnode=i;
            }
        }

        visited[nextnode]=1;

        for(int i=0;i<n;i++)
        {
            if(!visited[i] && min+cost[nextnode][i]<dist[i])
                dist[i]=min+cost[nextnode][i];
        }
    }

    for(int i=0;i<n;i++)
        cout<<"Distance to "<<i<<" = "<<dist[i]<<endl;
}






#knapsack 
#include<iostream>
using namespace std;

int main()
{
    int n,w;
    cin>>n;

    int profit[n],weight[n];

    for(int i=0;i<n;i++)
        cin>>profit[i];

    for(int i=0;i<n;i++)
        cin>>weight[i];

    cin>>w;

    int dp[n+1][w+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(weight[i-1]<=j)
                dp[i][j]=max(profit[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }

    cout<<"Maximum Profit = "<<dp[n][w];
}
