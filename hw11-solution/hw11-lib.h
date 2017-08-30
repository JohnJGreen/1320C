struct node {
    char* word;
    int count;
    struct node* left;
    struct node* right;
};


struct node* readData( void );
struct node* addNode(char *word);
void insert(struct node *root, char* word);
void printTree(struct node* root);
void freeMem(struct node* root);
