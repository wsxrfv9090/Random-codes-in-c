#include "struct.h"
#include <stdlib.h>
#include <stdio.h>

HuffmanNode* initHuffmanNode(char character, float frequency) {
    HuffmanNode* node = (HuffmanNode*)malloc(sizeof(HuffmanNode));
    if (node != NULL) {
        node->character = character;
        node->frequency = frequency;
        node->left = NULL;
        node->right = NULL;
    }
    else
        printf("ERROR:initHuffmanNode function memory alloction failed.\n");
    return node;
}

LinkQueue Qinit() {
    LinkQueue queue = (LinkQueue)malloc(sizeof(*queue));
    if (queue != NULL) {
        queue->QueueLength = 0;
        queue->front = NULL;
        queue->rear = NULL;
    }
    else
        printf("ERROR:Qinit function memory alloction failed.\n");
    return queue;
}

void InsertNode(LinkQueue queue, HuffmanNode data) {
    QLinkNode* newNode = (QLinkNode*)malloc(sizeof(QLinkNode));
    if (newNode == NULL) {
        printf("ERROR:InsertNode function memory allocation failed.\n");
        return;
    }
    newNode->data = data; // 设置数据
    newNode->next = NULL; // 新节点将是最后一个节点
    if (queue->rear != NULL) {
        newNode->prev = queue->rear; // 新节点的前一个节点是当前的尾节
        queue->rear->next = newNode; // 更新当前尾节点的next
    }
    queue->rear = newNode; // 更新队列的尾指针
    if (queue->front == NULL)
        queue->front = newNode; // 如果队列为空，则新节点也是头节点
    queue->QueueLength++;
    return;
}

int LengthOfQueue(LinkQueue queue) {
    if (queue->front == NULL)
        return 0;
    QLinkNode* current = queue->front;
    int count = 0;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

QLinkNode* FindMid(LinkQueue queue) {
    if (queue == NULL || queue->front == NULL)
        return NULL;
    QLinkNode* fast = queue->front;
    QLinkNode* slow = queue->front;
    if (fast->next != NULL) {
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
    }
    else
        printf("One element in FindMid variable queue.\n");
    return slow;
}

void FreeQueue(LinkQueue queue) {
    QLinkNode* current = queue->front;
    while (current != NULL) {
        QLinkNode* temp = current;
        current = current->next;
        free(temp);
    }
    free(queue);
}

LinkQueue merge(LinkQueue leftQ, LinkQueue rightQ) {
    QLinkNode* leftFlag = leftQ->front;
    QLinkNode* rightFlag = rightQ->front;

    LinkQueue TempQ = Qinit();

    while (leftFlag != NULL && rightFlag != NULL) {
        if (leftFlag->data.frequency <= rightFlag->data.frequency) {
            if (TempQ->front == NULL) {
                TempQ->front = leftFlag;
                TempQ->rear = leftFlag;
                TempQ->front->prev = NULL;
                leftFlag = leftFlag->next;
                TempQ->rear->next = NULL;
            }
            else {
                leftFlag->prev = TempQ->rear;
                TempQ->rear->next = leftFlag;
                TempQ->rear = leftFlag;
                leftFlag = leftFlag->next;
                TempQ->rear->next = NULL;
            }
        }
        else if (rightFlag->data.frequency < leftFlag->data.frequency) {
            if (TempQ->front == NULL) {
                TempQ->front = rightFlag;
                TempQ->rear = rightFlag;
                TempQ->front->prev = NULL;
                rightFlag = rightFlag->next;
                TempQ->rear->next = NULL;
            }
            else {
                rightFlag->prev = TempQ->rear;
                TempQ->rear->next = rightFlag;
                TempQ->rear = rightFlag;
                rightFlag = rightFlag->next;
                TempQ->rear->next = NULL;
            }
        }
    }
    while (leftFlag != NULL) {
        leftFlag->prev = TempQ->rear;
        TempQ->rear->next = leftFlag;
        TempQ->rear = leftFlag;
        leftFlag = leftFlag->next;
        TempQ->rear->next = NULL;
    }
    while (rightFlag != NULL) {
        rightFlag->prev = TempQ->rear;
        TempQ->rear->next = rightFlag;
        TempQ->rear = rightFlag;
        rightFlag = rightFlag->next;
        TempQ->rear->next = NULL;
    }
    free(leftQ);
    free(rightQ);
    return TempQ;
}

LinkQueue splitQ(LinkQueue queue, QLinkNode* Mid) {
    if (queue->front == NULL || Mid == NULL) {
        printf("ERROR:splitQfunction got Null as a variable.\n");
        return NULL;
    }
    else if (Mid == queue->front) {
        printf("Mid == queue->front\n");
        return NULL;
    }

    LinkQueue LstQueue = Qinit();
    LstQueue->front = Mid;
    LstQueue->rear = queue->rear;
    LstQueue->QueueLength = LengthOfQueue(LstQueue);
    LstQueue->rear->next = NULL;

    QLinkNode* FstEnd = Mid->prev;
    Mid->prev = NULL;
    if (FstEnd != NULL) {
        FstEnd->next = NULL;
        queue->rear = FstEnd;
        queue->front->prev = NULL;
    }
    queue->QueueLength = LengthOfQueue(queue);

    return LstQueue;
}

LinkQueue process(LinkQueue queue) {
    if (queue->front == queue->rear)
        return;
    QLinkNode* mid = FindMid(queue);
    LinkQueue rightQueue = splitQ(queue, mid);
    LinkQueue LeftSorted = process(queue);
    LinkQueue RightSorted = process(rightQueue);
    LinkQueue MergedQueue = merge(LeftSorted, RightSorted);
    return MergedQueue;
}

LinkQueue MergeSort(LinkQueue queue) {
    if (queue == NULL) {
        printf("ERROR: Function MergeSort got a NULL as a variable.\n");
        return NULL;
    }
    LinkQueue MergedQueue = process(queue);
    return MergedQueue;
}

HuffmanNode* RemoveFirstQE(LinkQueue queue) {
    if (queue->front == NULL) {
        printf("ERROR: Wrong variable was passed into the RemoveFirstQE function!");
        return NULL;
    }
    HuffmanNode* temp = (HuffmanNode*)malloc(sizeof(HuffmanNode));
    if (temp == NULL) {
        printf("ERROR: Memory allocation failed.\n");
        return NULL;
    }
    temp->character = queue->front->data.character;
    temp->frequency = queue->front->data.frequency;
    temp->left = queue->front->data.left;
    temp->right = queue->front->data.right;
    QLinkNode* tempQ = queue->front;
    queue->front = tempQ->next;
    if (queue->front == NULL) {
        queue->rear = NULL; 
    }
    else {
        queue->front->prev = NULL;
    }
    free(tempQ);
    return temp;
}

HuffmanNode* createHuffmanNode(HuffmanNode* HNode1, HuffmanNode* HNode2) {
    HuffmanNode* NewNode = (HuffmanNode*)malloc(sizeof(HuffmanNode));
    if (NewNode != NULL) {
        NewNode->character = '-1';
        NewNode->frequency = HNode1->frequency + HNode2->frequency;
        NewNode->left = HNode1;
        NewNode->right = HNode2;
    }
    else
        printf("ERROR:initHuffmanNode function memory alloction failed.\n");
    return NewNode;
}

HuffmanNode* BuildHuffmanTree(LinkQueue queue) {
    
    while (queue->front != queue->rear && queue->front != NULL) {
        HuffmanNode* HuffNode1 = RemoveFirstQE(queue);
        HuffmanNode* HuffNode2 = RemoveFirstQE(queue);

        if (HuffNode1 == NULL || HuffNode2 == NULL) {
            printf("ERROR: Failed to remove nodes from the queue.\n");
            return NULL;
        }

        HuffmanNode* NewNode = createHuffmanNode(HuffNode1, HuffNode2);
        InsertNode(queue, *NewNode);
        queue = MergeSort(queue);
    }
    if (queue->front != NULL) {
        return &(queue->front->data);
    }
    else {
        return NULL;
    }
}

void PreOrderTraversal(HuffmanNode* root, int* path, int pathLen) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        printf("Character: %c, Frequency: %f, Path: ", root->character, root->frequency);
        for (int i = 0; i < pathLen; i++)
            printf("%d", path[i]);
        printf(" PathLength: %d",pathLen);
        printf("\n");
    }
    if (root->left != NULL) {
        path[pathLen] = 0;
        PreOrderTraversal(root->left, path, pathLen + 1);
    }
    if (root->right != NULL) {
        path[pathLen] = 1;
        PreOrderTraversal(root->right, path, pathLen + 1);
    }
}





