#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
//FUNCIONES DE ALTO NIVEL
//NO FUNCIONA EL REMOVE
static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;

    this = (LinkedList*) malloc(sizeof(LinkedList));
    if(this!=NULL)
    {
        this->size = 0;
        this->pFirstNode = NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        returnAux = this->size;
    }


    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int i;
    if(this != NULL && nodeIndex > -1 && nodeIndex < ll_len(this)) //CONDICIONES DE NULIDAD
    {
        if(this->pFirstNode != NULL) //VERIFICO SI NO ES NULO
        {
            pNode = this->pFirstNode; //GUARDO EL PUNTERO DEL PRIMER NODE EN EL NODO OBTENIDO
            for(i = 0; i < nodeIndex;i++)
            {
                pNode = pNode->pNextNode;
            }
        }
    }


    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{

    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* prev = NULL;
    Node* next = NULL;
    Node* nuevoNodo = NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
        nuevoNodo = (Node*)malloc(sizeof(Node));
        if(nuevoNodo != NULL)
        {
            nuevoNodo->pElement = pElement;
            if(nodeIndex == 0 && ll_len(this) == 0)
            {
                this->pFirstNode = nuevoNodo;
            }
            prev = getNode(this,nodeIndex-1);
            if(prev != NULL)
            {
                prev->pNextNode = nuevoNodo;
            }
            if(ll_len(this) == nodeIndex)
            {
                next = getNode(this,nodeIndex);
                if(next != NULL)
                {
                    next->pNextNode = nuevoNodo;
                    nuevoNodo->pNextNode = NULL;
                }

            }
            this->size++;
        }
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* actual;
    int len;
    if(this != NULL)
    {
        len = ll_len(this);
        addNode(this,len,pElement);
        returnAux = 0;
    }
    return returnAux;
}
//  ******* OJO CORREGIR *******************
/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* actual = NULL;
    int len;

    if(this!=NULL && index >= 0 && index < ll_len(this))
    {
        actual = getNode(this,index);
        if(actual != NULL)
        {
            returnAux = actual->pElement;
        }
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* actual;
    int cantidad;
    void* pElement1;
    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        actual = getNode(this,index);
        if(actual != NULL)
        {
            actual->pElement = pElement;
            returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* prev = NULL;
    Node* actual = NULL;
    Node* next = NULL;
    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        actual = getNode(this,index);
        if(actual != NULL)
        {
            next = getNode(this,index+1);
            if(next != NULL && index == 0)
            {
                this->pFirstNode = next;
                free(actual);
                this->size--;
            }else
            {
                prev = getNode(this,index-1);
                if(prev != NULL && index == ll_len(this)-1)
                {
                    prev->pNextNode = NULL;
                    free(actual);
                    this->size--;
                }else
                {
                    next = getNode(this,index+1);
                    if(next != NULL)
                    {
                        prev->pNextNode = next;
                        free(actual);
                        this->size--;
                    }

                }
            }

        }

        returnAux = 0;
    }


    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    Node* nodo;
    int i;
    int len;
    if(nodo != NULL)
    {
        len = ll_len(this);
        for(i = 0; i < len; i++)
        {
            nodo = getNode(this,i);
            free(nodo);
            returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        ll_clear(this);
        free(this);
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    void* Element;
    if(this != NULL)
    {
        for(i = 0; i < ll_len(this); i++)
        {
            Element = ll_get(this,i);
            if(Element == pElement)
            {
                returnAux = i;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        if(ll_len(this) > 0)
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
        addNode(this,index,pElement);
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node* nodo;
    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
        nodo = getNode(this,index);
        if(nodo != NULL)
        {
            returnAux = nodo->pElement;
            ll_remove(this,index);
            this->size--;
        }

    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    int index;
    if(this != NULL)
    {
        index = ll_indexOf(this,pElement);
        if(index >= 0)
        {
            returnAux = 1;
        }else
        {
            if(index == -1)
            {
                returnAux = 0;
            }
        }

    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;
    int j;
    int index;
    int counter = 0;
    int ret;
    void* element2;

    if(this != NULL && this2 != NULL)
    {

        for(i = 0; i < ll_len(this2); i++)
        {
            element2 = ll_get(this2,i);
            ret = ll_contains(this,element2);
            if(ret == 1)
            {
                counter++;
            }
        }
        if(counter == ll_len(this2))
        {
            returnAux = 1;
        }
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    void* pElement;
    if(this != NULL && from >= 0 && from < ll_len(this) && to > from && to <= ll_len(this))
    {
        cloneArray = ll_newLinkedList();
        for(i = from; i < to; i++)
        {
            addNode(cloneArray,i,ll_get(this,i));
            cloneArray->size++;
        }
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    Node* nodo;

    void* pElement;
    int i;
    if(this != NULL)
    {
        cloneArray = ll_newLinkedList();
        if(cloneArray != NULL)
        {
            for(i = 0; i < ll_len(this); i++)
            {
                nodo = getNode(this,i);
                if(nodo != NULL)
                {
                    pElement = nodo->pElement;
                    addNode(cloneArray,i,pElement);
                }
            }
        }

    }


    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux = -1;
    void* pAux = NULL;
    int i;
    int j;
    void* pElement1 = NULL;
    void* pElement2 = NULL;
    if(this != NULL && pFunc != NULL && (order == 1 || order == 0));
    {
        returnAux = 0;
        for(i = 0; i < ll_len(this)-1; i++)
        {
            for(j = i+1; j < ll_len(this);j++)
            {
                pElement1 = ll_get(this,i);
                pElement2 = ll_get(this,j);
                if(order == 0)
                {
                    if(pFunc(pElement1,pElement2) < 0)
                    {
                        pAux = pElement1;
                        ll_set(this, i, pElement2);
                        ll_set(this, j, pElement1);
                    }
                    else if(pFunc(pElement1,pElement2) > 0)
                    {
                        continue;
                    }
                }
                else if(order == 1)
                {
                    if(pFunc(pElement1,pElement2) > 0)
                    {
                        pAux = pElement1;
                        ll_set(this, i, pElement2);
                        ll_set(this, j, pElement1);
                    }
                    else if(pFunc(pElement1,pElement2) < 0)
                    {
                        continue;
                    }
                }

            }
        }
        for(i = 0; i < ll_len(this)-1; i++)
        {
            for(j = i+1; j < ll_len(this);j++)
            {
                pElement1 = ll_get(this,i);
                pElement2 = ll_get(this,j);
                if(pFunc(pElement1,pElement2) < 0 && order == 0)
                {
                    pAux = pElement1;
                    ll_set(this, i, pElement2);
                    ll_set(this, j, pElement1);
                }
            }
        }

    }



    //return returnAux;
}

