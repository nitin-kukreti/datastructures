#include<iostream>
using namespace std;
class array
{
private:
    int* Arr;
    int size;
    int length;
public:
int lengthreturn(){
    return length;
}
    void display();

    int pop();

    int remove(int index);

    array(int size);

   void append(int element);
   
   int insert(int element,int index);

   int getsize(){return size;}

    ~array();
};
array::array(int size)
{
    Arr=new int[size];
    this->size=size;
    length=0;
}

int array::remove(int index)
{
   if(index>0 && index<length){
       for (int i = index-1; i < length; i++)
       {
           Arr[i]=Arr[i+1];
       }
       length--;
       return 1;
   }else{
       cout<<"\ninvalid index\n";
       return 0;
   }
}


int array::pop(){
    if(length>0){
        length--;
        return 1;
    }else{
        cout<<"\n array is empty\n";
        return 0;
    }
}

void array::display(){
    if(length>0){
      for (int i = 0; i < length; i++)
        {
            cout<<Arr[i]<<" ";
        }  
    }else{
        cout<<"\narray is empty\n";
    }
    cout<<endl;
}





void array::append(int element)
{
   if(length<size){
       Arr[length++]=element;
       cout<<"\nelement sucessfuly inserted\n";
   }else
   {
       cout<<"\narray is overflow\n";
   }
}


int array::insert(int element,int index)
{
    if(index>=0 && index <length){
    int length_instance;
    if(length>=size)
    {
        cout<<"\narray is full if you want to insert one element will be lost press 1 for inertion press 0 for not\n";
        int choice;
        cin>>choice;
        if(choice!=1){
         return 0;
        }
    }else{
        length_instance=length;
        length++;       
    }
    for (int i =length_instance ; i >=index-1; i--)
    {
        Arr[i+1]=Arr[i];
    }
    Arr[index-1]=element;
    return 1;
    }else{
        cout<<"\nindex is invalid\n";
        return 0;
    }
}

array::~array()
{
    delete[] Arr;
}


int main(int argc, char const *argv[])
{
   int size,ch,index,element;
   cout<<"enter size of an array\n";
   cin>>size;
   array arr(size);
   while(true){
       cout<<"current length: "<<arr.lengthreturn()<<"  size of array :"<<arr.getsize()<<endl;
    cout<<"\nchoose among this\n";
    cout<<"1 for append value in an array\n";
    cout<<"2 for insert value in an array\n";
    cout<<"3 for pop value from the array\n";
    cout<<"4 for remove value from the array\n";
    cout<<"5 for display array elements\n";
    cin>>ch;
    switch (ch)
    {
    case 1:
        cout<<"enter integer element which you want to append\n";
        cin>>element;
        arr.append(element);
        break;
    
    case 2:
        cout<<"enter integer element and index which you want to insert\n";
        cin>>element>>index;
        arr.insert(element,index);
        break;
    
    
    case 3:
        arr.pop();
        break;
    

    case 4:
        cout<<"enter index which you want to delete\n";
        cin>>index;
        arr.remove(index);
        break;

    case 5:
        arr.display();
        break;

    default:
     exit(1);
        break;
    }
   }
    return 0;
}

