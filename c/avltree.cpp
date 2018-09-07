     #include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#define rep(i,a,b) for(int i=a;i<=b;i++>
#define drep(i,a,b) for(int i=a,i>=b;i-->
using namespace std;
int s[100005][2],flat=0;
typedef struct AVLTree* Node;
int n;//整个树的高度 
 struct AVLTree
{
	int key;				//关键字，用于AVL排序 
	int height;				//深度 
	struct AVLTree *left;
	struct AVLTree *right; 
};
Node avltree_create_node(int key,Node left,Node right)
{							//创建树 
 	Node p;
 	//cout<<"1"<<endl;
 	if((p=(Node)malloc(sizeof(AVLTree)))==NULL)return NULL;
 	p->key=key;
 	p->height = 0;
 	p->left=left;
 	p->right=right;
 	return p;
}
int avltree_height(Node tree)
{
	if(tree==NULL)return 0;
	else return tree->height;
}
int max(int a,int b)
{
	if(a>b)return a;
	else return b;
}
//四种错误情况 
Node ll(Node k) 	//左左 
{
	Node k1;
	k1=k->left;
	k->left=k1->right;
	k1->right=k;
	k->height=max(avltree_height(k->left),avltree_height(k->right))+1;
	k1->height=max(avltree_height(k1->left),k->height)+1;
	return k1;
}
Node rr(Node k1) 	//右右 
{
	Node k;
	k=k1->right;
	k1->right=k->left;
	k->left=k1;
	k1->height=max(avltree_height(k1->left),avltree_height(k1->right))+1;
	k->height=max(avltree_height(k->right),k1->height)+1;
	return k;
}
Node lr(Node k2) 	//左右 
{
	k2->left=rr(k2->left);
	return ll(k2);
}
Node rl(Node k3) 	//左右 
{
	k3->right=ll(k3);
	return rr(k3);
}
Node avltree_insert(Node avltree,int key)
{
	if(avltree==NULL)//一开始 
	{
		//新建节点
		avltree=avltree_create_node(key,NULL,NULL);
		//if(tree==NULL)报错 
	}	
	else if(key<avltree->key)// 左边 
	{
	//	cout<<"a";
	avltree->left = avltree_insert(avltree->left, key);
	if(avltree_height(avltree->left)-avltree_height(avltree->right)==2)
	{
		if(key<avltree->left->key)avltree=ll(avltree);
		else  avltree=lr(avltree);
	}	
	}
	else if(key > avltree->key)//右边 
	{
	//	cout<<"b";
	avltree->right = avltree_insert(avltree->right, key);
	if(avltree_height(avltree->right)-avltree_height(avltree->left)==2)
	{
		if(key > avltree->right->key)avltree=rr(avltree);
		else  avltree=rl(avltree);
	}
	//else if(key==avltree->key)报错	
	} 
	avltree->height=max(avltree_height(avltree->left),avltree_height(avltree->right))+1;
	//cout<<tree->height<<endl;
	return avltree;
}
void preorder_avltree(Node avltree)
{
	if(avltree != NULL)
	{
		s[avltree->key][1]=n-avltree_height(avltree)+1;
		preorder_avltree(avltree->left);
		preorder_avltree(avltree->right);	
	}
	return ;	
}

int main()
{
	int a,i;
	AVLTree *AVLtree=NULL;
	cin>>a;
	for(i=0;i<a;i++)
	{
		scanf("%d",&s[i][0]);
		AVLtree=avltree_insert(AVLtree,s[i][0]);
	}
	n=avltree_height(AVLtree);
	//cout<<n<<endl;
	preorder_avltree(AVLtree);
	printf("%d",s[s[0][0]][1]);
	for(i=1;i<a;i++)
	{
		printf(" %d",s[s[i][0]][1]);
	}
	cout<<endl;
	return 0;
}
