#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct node
{
	int data;
	struct node* next;
};
typedef struct node nd;
nd* create_node(int);//construct a new node
int destroy_node(nd**start);//destruct the nodes after usage
int insert_begin(nd**start,int value);
int insert_after(nd**addr,int value);// addr is the addres of the prev node
int insert_end(nd** end,int value);
int del_begin(nd**start);
int del_end(nd**start);
int del_pos(nd**addr);//here addr is the prev address
int display(nd*start);//returns the number of nodes visited
//int l_search(const nd*start,int key,nd**retaddr);
nd* find_insert_point( nd*start,int val,char mode);
//if 'key'->return the previous node addr,'pos'->prev node addr

//function declarations: 
nd* create_node(int value)// 1
{
	nd* newnode=(nd*)malloc(sizeof(nd));
	if(!newnode)
	{
		printf("\nNOT SUFFICIENT MEMORY.\n");
		exit(0);
	}
	newnode->next=NULL;
	newnode->data=value;
	return(newnode);
}

int destroy_node(nd**start)//2
{
	nd* current=NULL;
  while(*(start)!=NULL)
	{
		current=*start;
		*start=(*start)->next;
		free(current);
	}
	*start=NULL;
	return 1;
}

int insert_begin(nd**start,int value)//3
{
	nd*temp=create_node(value);
	temp->next=*start;
	*start=temp;
	return(1);
}

int insert_end(nd**end,int value)//5
{
	if((*end)!=NULL)
	{
		nd*temp=create_node(value);
		(*end)->next=temp;
		*end=temp;
		return(1);
	}
	else
	{
		printf("\nADDRESS:NULL\n");
		return(0);
	}
	
}

int insert_after(nd**addr,int value)//4
{
	if((*addr)!=NULL)
	{
		nd*temp=create_node(value);
		temp->next=(*addr)->next;
		(*addr)->next=temp;
		return(1);
	}
	else
	{
		printf("\nADDRESS:NULL\n");
		return(0);
	}
}

int del_begin(nd**start)//6
{
	if((*start)!=NULL)
	{
		nd*temp=*start;
		*start=(*start)->next;
		free(temp);
		return(1);
	}
	else
	{
		printf("\nADDRESS:NULL\n");
		return(0);
	}
}

int del_end(nd**start)//7
{
	if((*start)==NULL)
	{
		printf("\nADDRESS:NULL\n");
		return(0);
	}
	if((*start)->next!=NULL)
	{
		free(*start);
		*start=NULL;
		return 1;
	}
	
		nd*temp=*start;
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}
		free(temp->next);
		temp->next=NULL;
		return 1;
}

int del_pos(nd**addr)//8
{
	if(*addr==NULL)
	{
		printf("\nADDRESS:NULL\n");
		return 0;
	}
	nd*temp=(*addr)->next;
	(*addr)->next=(*addr)->next->next;
	free(temp);
	return 1;
}

int display(nd*start)//9
{
	if(start==NULL)
	{
		printf("\nNO LINKED LIST AVALIABLE.\n");
		return 0;
	}
	nd*temp=start;
	int count=0;
	while(temp!=NULL)
	{
		printf("\n%d",temp->data);
		temp=temp->next;
		count++;
	}
	return (count);
}

nd* find_insert_point(nd*start,int val,char mode)//10
//if 'k'->return the current node addr,'p'->prev node addr
{
	if(start!=NULL)
	{
		if(toupper(mode)=='K')
		{
			if(start->data == val)
			{
				return NULL;
			}
			 nd*prev = start;
			while(prev->next!=NULL && prev->next->data!=val)
			{
				prev =prev->next;
			}
			return(prev);
		}
		else if(toupper(mode)=='P')
		{
		  if(val<=1)
		  {
		  	return NULL;
		  }
			nd*temp2=start;
			int count =1;
			while(temp2!=NULL && count<val-1 )
			{
				temp2=temp2->next;
				count++;
			}
			return(temp2);
		}
		else
		{
			printf("\nENTER VALID MODE:P->POSITION||K->KEY");
			return NULL;
		}
	}
	else
	{
		return NULL;
	}

}

int main()
{
	nd* start,*temp,*end;
	start=end=temp=NULL;
	int value,key,n=0;
	value=key=0;
	int sw=0;
	
	
	
	while(1)
	{
		printf("\nMENU:\n1.CREATE\n2.INSERT AT BEGINING\n3.INSERT AT THE END");
		printf("\n4.INSERT AFTER SPECIFIC VALUE\n5.INSERT AFTER SPECEFIC LOCATION\n");
		printf("\n6.DELETE FROM BEGINING\n7.DELETE FROM END\n8.DELETE ANY SPECIFIC VALUE");
		printf("\n9.DELETE FROM ANY SPECIFIC LOCATION\n10.TRAVERSAL\n11.COUNT\n12.LINEAR SEARCH.\n13.EXIT");
		printf("\nENTER YOUR CHOICE:");
		scanf("%d",&sw);
		switch(sw)
		{
			case 1:
				{do
        	{
        		printf("\nENTER DATA TO INSERT:");
        		scanf("%d",&value);
        		temp=create_node(value);
        		if(start==NULL)
	        	{
		         	start=end=temp;
		        }
		        else
		        {
			        end->next=temp;
		        	end=temp;
	        	}
	         	printf("\nWANT TO CONTINUE(1/0):");
		        scanf("%d",&n);
		
	        }
	         while(n!=0);
	         printf("\nPRINTING DATA\n");
          	display(start);
	         break;
	        } 
	     case 2:
	     {
	     	printf("\nENTER THE VALUE TO INSERT:");
	     	scanf("%d",&value);
	     	insert_begin(&start,value);
	     	printf("\nPRINTING DATA\n");
        display(start);
	     	break;
	     	}
	     	
	    case 3:
	    	{
	    	printf("\nENTER THE VALUE TO INSERT:");
	     	scanf("%d",&value);
	     	insert_end(&end,value);	
	     	printf("\nPRINTING DATA\n");
        display(start); 
	     	break;
	     	}
	     	
	    case 4:
	    	{
    		printf("\nENTER THE VALUE TO INSERT AFTER:");
   		 	scanf("%d",&key);
   		 	printf("\nENTER THE VALUE TO INSERT:");
    		scanf("%d",&value);

    		if(start != NULL && start->data == key)
    				{
        			insert_after(&start,value);   // key is the head node itself
   	 				}
    		else
    				{
        			nd* help = find_insert_point(start,key,'k');
        			if(help == NULL)
        		{
            	printf("\nVALUE NOT FOUND.\n");
        		}
        else
        {
            insert_after(&(help->next),value);
        }
   		 }
    		printf("\nPRINTING DATA\n");
    		display(start);
    		break;
				}	
      
      case 5:
      	{
    		printf("\nENTER THE POSITION TO INSERT AFTER:");
    		scanf("%d",&key);
    		printf("\nENTER THE VALUE TO INSERT:");
    		scanf("%d",&value);

    		if(key == 1 && start != NULL)
    		{
        	insert_after(&start,value);      // insert right after the head
    		}
    		else
    		{
        	nd* help = find_insert_point(start, key+1, 'P');
        	if(help == NULL)
        		{
            printf("\nINVALID POSITION.\n");
        		}
        		else
        		{
        	    insert_after(&help,value);
        		}
    		}
    		printf("\nPRINTING DATA\n");
    		display(start);
    		break;
				}
        
     case 6:
     	 {
     	 printf("\nDELETING FROM BEGINING:");
     	 del_begin(&start);
     	 display(start);
     	 break;
     	 }
    case 7:
     	 {
     	 printf("\nDELETING FROM END:");
     	 del_end(&start);
     	 display(start);
     	 break; 
     	 }
    case 8:
	    	
			{
    		printf("\nENTER THE VALUE TO DELETE :");
   		 	scanf("%d",&key);
	
   		 if(start != NULL && start->data == key)
    		{
        	del_begin(&start);
    		}
    		else
    			{
        	nd* help = find_insert_point(start,key,'k');
        	if(help == NULL)
        	{
            printf("\nVALUE NOT FOUND.\n");
        	}
        	else
        	{
            del_pos(&help);
        	}
    			}
    				printf("\nPRINTING DATA\n");
    				display(start);
    				break;
				}	  	    	
     case 9:
	    	{
	    	printf("\nENTER THE POSITION TO DELETE :");
	     	scanf("%d",&key); 
	     	nd*help=find_insert_point(start,key,'p');
	     	del_pos(&help);
	     	printf("\nPRINTING DATA\n");
        display(start);
        break;
        }
     case 10:
     		{
     		printf("\nTRAVERSAL:\n");
     		display(start);
     		break;
     		}
     case 11:
        {
        printf("\nPRINTING DATA:\n");
     		int count=display(start);
     		printf("\nTOTAL NUMBER OF NODES:%d\n",count);
     		break;
     		}
     case 12:
				{
    		printf("\nENTER THE VALUE TO SEARCH:");
    		scanf("%d",&key);

    		if(start != NULL && start->data == key)
    		{
        	printf("\nVALUE FOUND AT:%p\n",(void*)start);
    		}
    		else
    		{
        	nd* help = find_insert_point(start,key,'k');
        	if(help == NULL)
        {
            printf("\nVALUE NOT FOUND.\n");
        }
        else
        {
            printf("\nVALUE FOUND AT:%p\n",(void*)help->next);
        }
   		 }
   		 break;
				}
	   case 13:
	   		{
	   		destroy_node(&start);
	   		printf("\nEXIT SUCCESSFUL.\n");
	   		exit(0);
	      }   
	   default:
	   		{
	   		printf("\nENTER A VALID CHOICE.\n");
	   		}
	   }   	   
		}
	
	return(1);
}
