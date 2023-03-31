/*void rotate(node tree[],int index) {
    int grandParent, parent, parentLeft, parentRight, VLeft, VRight;
    parent  = tree[index].parent;
    if(parent != INT_MAX){
        if(tree[parent].right == index){
            grandParent = tree[parent].parent;
            if(grandParent != INT_MAX && tree[grandParent].right == parent)
                tree[grandParent].right = index;
            else if(grandParent != INT_MAX && tree[grandParent].left == parent)
                tree[grandParent].left = index;
            tree[index].parent = grandParent;
            VRight = tree[index].right;
            tree[index].right = parent;
            tree[parent].parent = index;
            tree[parent].right = VRight;
            if(VRight != INT_MAX)
                tree[VRight].parent = parent;
        }else{
            grandParent = tree[parent].parent;
            if(grandParent != INT_MAX && tree[grandParent].right == parent)
                tree[grandParent].right = index;
            else if(grandParent != INT_MAX && tree[grandParent].left == parent)
                tree[grandParent].left = index;
            tree[index].parent = grandParent;
            VLeft = tree[index].left;
            tree[index].left = parent;
            tree[parent].parent = index;
            tree[parent].left = VLeft;
            if(VLeft != INT_MAX)
                tree[VLeft].parent = parent;
        }
    }
}*/