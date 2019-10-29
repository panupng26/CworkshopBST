#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node 
{
	int data ;
	struct node *left;
	struct node *right;
}ptr;
void showmenu()
{
	printf("Menu\n");
	printf("=================\n");
	printf("1. Insert Node\n");
	printf("2. Search Node\n");
	printf("3. Delete Node\n");
	printf("4. Print Inorder\n");
	printf("5. Print Preorder\n");
	printf("6. Print Postorder\n");
	printf("7. Exit Program\n");	
	printf("==================\n");
}

void insertnode(ptr **root,int newdata)
{
	ptr *run,*prev,*newnode;
	newnode = (ptr*)malloc(sizeof(ptr));
	newnode->data = newdata;
	newnode->left = NULL;
	newnode->right = NULL;
	if(*root == NULL)
	{
		*root = newnode;
	}else
		{
			run = *root;
			while(run!=NULL)
			{
				prev = run;
				if(newnode->data < run->data)
				{
					run = run->left;
				}else
					{
						run = run->right;
					}
			}
			if(newnode->data < prev->data)
			{
				prev->left = newnode;
			}else if(newnode->data > prev->data)
				{
					prev->right = newnode;
				}
		}
}

void createBST(ptr **root)
{
	int i,newdata,amount ;
	printf("Enter amount : ");
	scanf("%d",&amount);
	
	for(i=1;i<=amount;i++)
	{
		printf("Enter value : ");
		scanf("%d",&newdata);
		insertnode(&*root,newdata);
	}

}
void printInorder(ptr *run)
{
   if(run != NULL)
   {
       printInorder(run->left);       //left (L)
       printf("%d ",run->data);  //Root(Rt)
       printInorder(run->right);     //Right (R)   
   }     
}

void printpreorder(ptr *run)
{
   if(run != NULL)
   {
       printf("%d ",run->data);  //Root(Rt)
       printpreorder(run->left);       //left (L)
       printpreorder(run->right);     //Right (R)   
   }     
}
void printpostorder(ptr *run)
{
   if(run != NULL)
   {
       
       printpostorder(run->left);       //left (L)
       printpostorder(run->right);     //Right (R)   
   	   printf("%d ",run->data);  //Root(Rt)
   }     
}
void serch(ptr *run,int target)
{
   if(run != NULL)
   {
   	serch(run->left,target);
    serch(run->right,target); 
   	if(target == run->data)
   	{
   	   printf("I'm serching found : ");
   	   printf("%d\n",run->data);
	}
		
	}
       
        
}

void deleteNode(ptr **root,ptr *prev,ptr *run)
{
	ptr *temp;
	if(run->left == NULL && run->right == NULL)
    {
    	if(run == *root) 
    	{
    		*root = NULL;
		}
    	else       
		{
			if(prev->left == run) 
		   {
		   	prev->left = NULL;
		   }
		   else
		   {
		   	prev->right = NULL;
		   }
		}      
		   
	}
	else if(run->left != NULL && run->right != NULL)
	{
		prev = run;
		temp = run->left;
		while(temp->right != NULL)
		{
			prev = temp;
			temp = temp->right;
		}
		run->data = temp->data;  
		if(prev == run)
		{
			prev->left = temp->left;
		}          
		else
		{
			prev->right = temp->left; 
		}
		free(temp);   
	}
	else if(run->left != NULL) 
	{
		if(run == *root)
		   *root = run->left;
		else 
		{
			if(prev->left == run)   
			{
				 prev->left = run->left;   
		    }     
		      
		    else {
		    	prev->right = run->left;  
			}                        
		        
		}
	}
	else //delete a node at right side
	{
		if(run == *root)
		   *root = run->right;
		else 
	    {
	    	if(prev->left == run) {          // delete node is at the left subtree 
	    	   prev->left = run->right;   //  a child node at the right side
			  }   
	    	else  {                           // delete node is at the right subtree
	    	   prev->right = run->right;      //  a child node at the right side
		}
		free(run);	
		}
	}
}	

void deleteBST(ptr **root,int target)
{
	ptr *run,*prev;
	run = *root;
	while(run != NULL && target != run->data)
	{
		prev = run;
		if(target > run->data)
		   run = run->right;
		else
		   run = run->left;		
	}
	if(run == NULL)
	{
		printf("\nTarget not found!");
		//return 0;
	}
	else
	{
	    deleteNode(&*root,prev,run);	
	    printf("Delete Complete\n");
    }
}

void program(ptr **root, int exit)
{
	int target;
	if(exit == 1)
	{
		createBST(&*root);
		printf("Insert Complete\n");
		printInorder(*root);
		printf("\n");
	}else if (exit == 2)
	{
		printf("Enter Node you want serch : ");
		scanf("%d",&target);
		serch(*root,target);
	}else if (exit == 3)
	{
		printf("Enter number Delete : ");
		scanf("%d",&target);
		deleteBST(&*root,target);
	}else if (exit == 4)
	{
		printInorder(*root);
		printf("\n");
	}else if (exit == 5)
	{
		printpreorder(*root);
		printf("\n");
	}else if (exit == 6)
	{
		printpostorder(*root);
		printf("\n");
	}
}
int main()
{
	ptr *root ;
	root = NULL;
	int exit;
	do{
		showmenu();
		printf("Please enter menu : ");
		scanf("%d",&exit);
		program(&root,exit);
	} 
	while(exit!=7);
	printf("Good byeeeeee!!!!");
	return 0;
}
