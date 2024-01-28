#pragma once
#include "struct.h"

LinkQueue Qinit();

HuffmanNode* initHuffmanNode(char character, float frequency);

void InsertNode(LinkQueue queue, HuffmanNode data);

void FreeQueue(LinkQueue queue);

int LengthOfQueue(LinkQueue queue);

LinkQueue MergeSort(LinkQueue queue);

HuffmanNode* BuildHuffmanTree(LinkQueue queue);

void PreOrderTraversal(HuffmanNode* root, int* path, int pathLen);
