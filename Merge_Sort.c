
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node* link;  
    
}NODE;


NODE* createNode();

NODE* input(NODE* header,int n);

NODE* append(NODE* header, int val);

void display(NODE* header,int n);

NODE* splitter(NODE* head,int n);

NODE* mergesort(NODE* header, int n);

int listlen(NODE* header);

int elefetch(NODE* header,int index);

NODE* merge(NODE* left,NODE* right);



int main(int argc, char const *argv[])
{
    int n;
    NODE* s = createNode();
    printf("Enter the number of elements in the array");
    scanf("%d",&n);

    s = input(s,n);
 
    display(mergesort(s,n),n);
    // printf("%d",listlen(mergesort(s,n)));


}




NODE* createNode()
{
    NODE* s = (NODE*)malloc(sizeof(NODE));
    s->link= NULL;
    return s;
}

NODE* input(NODE* header,int n)
{
     
    NODE* p = header;
    for(int i = 0; i < n;i++)
    {
        scanf("%d", &header->value);
        if(i!= n-1)
        {
            header->link = createNode();
        }
        else
        {
            header->link = NULL;
        }
        header = header->link;
    }
    return p;
}



NODE* append(NODE* header, int val)
{
    NODE* p = header;
    while(header->link != NULL)
    {
        header = header->link;
    }
    NODE* NewNode = createNode();
    NewNode->value = val;
    NewNode->link = NULL;
    header->link = NewNode;

    return p;
}


void display(NODE* header,int n)
{
    for(int i = 0;i<n-1;i++)
    {
        header = header->link;
    }
    while(header!= NULL)
    {
        printf("\n%d\n",header->value);
        header = header->link;
    }
}

NODE* splitter(NODE* head,int n)
{
    int mid = n/2;
    NODE* left_node = head;
    for(int k = 0;k<mid-1;k++)
    {
        head = head->link;
    }
    NODE* right_node = head->link ;
    head->link= NULL;

    return right_node;
}

int listlen(NODE* header)
{
    int count = 0;
    while(header!=NULL)
    {
        count++;
        header = header->link;
    }
    return count;
}


int elefetch(NODE* header,int index)
{
    int curr_index = 0;
    while(curr_index!=index)
    {

        header = header->link;
        curr_index++;
    }
    return header->value;

}

NODE* mergesort(NODE* header, int n)
{
    int count = listlen(header);
    if (count==1)
    {
        return header;
    }
    NODE* right = splitter(header,n);
    right = mergesort(right,listlen(right));
    NODE* left = header;
    left = mergesort(left,listlen(left));
    return merge(left,right);
}

NODE* merge(NODE* left,NODE* right)
{
    NODE* out = createNode();
    NODE* rethead = out;
    int i = 0;
    int j = 0;
    while((i<listlen(left))&&(j<listlen(right)))
    {
        if (elefetch(left,i) >= elefetch(right,j))
        {
            append(out, elefetch(right,j));
            j++;
        }
        else
        {
            append(out, elefetch(left,i));
            i++;
        }
    
    }

    while (i < listlen(left))
    {
        append(out, elefetch(left, i));
        i++;
    }

    while (j < listlen(right))
    {
        append(out, elefetch(right, j));
        j++;
    }
    return rethead;

}