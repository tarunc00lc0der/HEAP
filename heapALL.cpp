#include<bits/stdc++.h>
using namespace std;

vector<int>maxheap;
vector<int>minheap;


void topdownmaxheapify(int i )
{ 
int max,l,r;
  max=i;
  l=2*i +1;
  r=2*i +2;
   if(l< maxheap.size() && maxheap[l]>maxheap[max])
   max=l;
   if(r< maxheap.size() && maxheap[r]>maxheap[max])
   max=r;
   if(max!=i)
   {int temp= maxheap[i];
   	    maxheap[i]=maxheap[max];
   	    maxheap[max]=temp;
       topdownmaxheapify(max);
   } 
}


void topdownminheapify(int i)
{
 int min=i;
 int l=2*i +1;
 int r=2*i +2;
 if(l<minheap.size() && minheap[l]<minheap[min])
   min=l;
   if(r<minheap.size() && minheap[r]<minheap[min])
   min=r;
   if(min!=i)
   {int temp= minheap[i];
   	    minheap[i]=minheap[min];
   	    minheap[min]=temp;
    topdownminheapify(min);
}
}

void bottomupmaxheapify(int i)
{
 int p=(i-1)/2;
 while(i>0 && maxheap[p] < maxheap[i])
 {
 	int temp= maxheap[i];
   	    maxheap[i]=maxheap[p];
   	    maxheap[p]=temp;
    i=p;
	p=(i-1)/2;
  }
}

void bottomupminheapify(int i)
{
 int p=(i-1)/2;
 while(i>0 && minheap[p] > minheap[i])
 {
 	int temp= minheap[i];
   	    minheap[i]=minheap[p];
   	    minheap[p]=temp;
    i=p;
	p=(i-1)/2;
  }
}

int deletemin(int i)
{  
     int val = minheap[i];
    minheap[i] = INT_MIN;
    bottomupminheapify(i);
    minheap[0] = minheap[minheap.size()-1];
    minheap.pop_back();
    topdownminheapify(0);
    return val;
}

int deletemax(int i)
{
	int val = maxheap[i];
    maxheap[i] = INT_MAX;
    bottomupmaxheapify(i);
    maxheap[0] = maxheap[maxheap.size()-1];
    maxheap.pop_back();
    topdownmaxheapify(0);
    return val;
}

void addmin(int element)
{
 minheap.push_back(element);
 bottomupminheapify(minheap.size()-1);	
}


void addmax(int element)
{
 maxheap.push_back(element);
 bottomupmaxheapify(maxheap.size()-1);	
}

void balanceheap()
{ 
 int diff = maxheap.size()-minheap.size();
  int elem;
   if(abs(diff)== 2)
   {
   	if(diff< 0)
   	{
     elem = deletemin(0);	
     addmax(elem);	
     }
   	else
   	 {
   	   elem=deletemax(0);
   	   addmin(elem);
   	 }
   	
   }
}


	


void addelement(int element)
{
 if(maxheap.size()==0)
   addmax(element);
else if(maxheap[0]< element)
    addmin(element);
else
    addmax(element);
 balanceheap();    
}
    


 double findmedian()
 { 
   double median;
   if(maxheap.size() < minheap.size())
      median=minheap[0];
   else if(maxheap.size()>minheap.size()) 
      median=maxheap[0]  ;
   else
      median= (double(maxheap[0]+minheap[0])/2.0);
   return median;
 }  
    
    



int main()
{
    int A[] = {12,4,5,3,8,7};
     for(int j=0;j<6;j++)
       {
       	addelement(A[j]);
       	
       	cout<< A[j] <<"   "<<fixed<<setprecision(1)<<findmedian() <<endl;
       	
       }
       	
	   
 return 0;
}	
	



