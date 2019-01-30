//
// Created by ���ֹ��� on 2019/1/28.
//

#include"SequenceList.h"
#include"DataElement.h"
#include<stdio.h>
#include<stdlib.h>

/**
 * ��ʼ��˳���
 * @param seqList    Ҫ��ʼ����˳���
 * @param elemArray  ��ʼ��ʱҪ��ӵ�Ԫ����������
 * @param length     ��ʼ��ʱ��ӵ�Ԫ�ظ���
 */
void InitList(SeqList * seqList, ElementType * elemArray, int length)
{
    //��ʼ��˳���ʱ��˳���ĳ�������!
    seqList->length = 0;
    if(seqList->length > MAX_SIZE)
    {
        printf("�����������������,��ʼ��ʧ��!");
        return;
    }
    //ÿ��ѭ�������±�Ϊi��λ�ò���һ��Ԫ��
    for(int i = 0; i < length; i++)
    {
        InsertElement(seqList, i, elemArray[i]);
    }
}

/**
 * ��˳���ָ�����±����Ԫ��
 * @param seqList    Ҫ��ʼ����˳���
 * @param index      Ҫ������±�
 * @param element    Ҫ�����Ԫ��
 */
void InsertElement(SeqList * seqList, int index, ElementType element)
{
    //1.��֤������Ԫ�ؿռ��Ƿ񳬹�MAX_SIZE
    //2.index��֮�Ƿ�Ϸ�[0,MAX_SIZE-1]
    //3.�����indexӦ����length֮��
    //4.�ӵ�length-1���±꿪ʼ,ǰ��һ��Ԫ�ظ�ֵ������һ��Ԫ��ֱ��index
    //5.��Ҫ�����ֵ������index��Ԫ��
    //6.˳�����ܳ���+1!!!!!!!!!!!!!!!!!!!!!!!!
    if(seqList->length + 1 > MAX_SIZE)
    {
        printf("��������,����Ԫ��ʧ��!\n");
        return;
    }
    if(index < 0 || index > MAX_SIZE - 1)
    {
        printf("ֻ����������±귶Χ�ڲ���Ԫ��[0,%d]\n",MAX_SIZE);
        return;
    }
    if(index > seqList->length)
    {
        printf("������±곬�����������󳤶�,����ʧ��\n");
        return;
    }
    //��C89��׼�в�������forѭ����ֱ�Ӷ������,C99����
    for(int i = seqList->length - 1; i >= index; i--)
    {
        seqList->datas[i + 1] = seqList->datas[i];
    }
    seqList->datas[index] = element;
    seqList->length++;
}

/**
 * ɾ��˳�����ָ���±��Ԫ��
 * @param   Ҫ������˳���
 * @param   Ҫɾ��Ԫ�ص��±�
 * @return  ����ɾ����Ԫ��,��ɾ��ʧ��,����NULL
 */
ElementType * DeleteElement(SeqList * seqList, int index)
{
    if(index < 0 || index > MAX_SIZE-1)
    {
        printf("�±�Խ��,�޷�ɾ��ָ��Ԫ��\n");
        return NULL;
    }

    //1.�ҵ�Ҫɾ����Ԫ��,���������Ա㷵��!!!(���������ɾ��Ԫ�صĸ���)
    //����ʹ����Ϻ����free,������������й¶!!!

    ElementType * delElement = (ElementType *)malloc(sizeof(ElementType));//�ص�!!!

    //�������岢���ò��Һ���,����Ҫɾ��Ԫ�ص�ָ��
    *delElement = *GetElement(seqList,index);

    //2.��ָ��λ��ɾ��,���һ��Ԫ�ظ�ֵ��ǰ��һ��Ԫ��
    for(int i = index; i < seqList->length - 1; i++)
    {
        seqList->datas[i] = seqList->datas[i + 1];
    }
    //3.˳����ܳ���-1
    seqList->length--;
    return  delElement;//����ʹ����Ϻ����free,������������й¶
}

/**
 * ����˳�����ָ���±��Ԫ��
 * @param   Ҫ������˳���
 * @param   Ҫ����Ԫ�ص��±�
 * @return  ����ָ���±��Ԫ��,������ʧ��,����NULL
 */
ElementType * GetElement(SeqList * seqList, int index)
{
    if(index < 0 || index > MAX_SIZE-1)
    {
        printf("�±�Խ��,�޷��ҵ�ָ��Ԫ��\n");
        return NULL;
    }
    ElementType * element;//Ҫ���ҵ�Ԫ��
    element = &seqList->datas[index];
}

/**����˳���ĳ���*/
int GetLength(SeqList * seqList)
{
    if(seqList->length == NULL)
    {
        return  0;
    }
    return seqList->length;
}

/**����˳����Ƿ�Ϊ��*/
int IsEmpty(SeqList * seqList)
{
    return GetLength(seqList) == 0 ? TRUE : FALSE;
}

/**���˳���*/
void ClearList(SeqList * seqList)
{
    if(seqList == NULL)
    {
        return;
    }
    seqList->length = 0;
}

/**
 * ��ӡ˳���
 * @param   Ҫ������˳���
 */
void PrintList(SeqList * seqList)
{
    for(int i = 0; i < seqList->length; i++){
        printf("%d\t%s\n", seqList->datas[i].id, seqList->datas[i].name);
    }
}

