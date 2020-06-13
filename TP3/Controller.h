
/** \brief open the text file and save the data in the linkedlist
 *
 * \param path char* name of file
 * \param pArrayListEmployee LinkedList* receive the linkedlist
 * \return int returns (1) ok
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief open the binary file and save the data in the linkedlist
 *
 * \param path char* name of file
 * \param pArrayListEmployee LinkedList* receive the linkedlist
 * \return int returns (1) ok
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief add an employee to the linkedlist
 *
 * \param pArrayListEmployee LinkedList* receive the linkedlist
 * \return int return (1) ok
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief edit a linkedlist employee
 *
 * \param pArrayListEmployee LinkedList* receive the linkedlist
 * \return int  return (1) ok
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief remove an employee from the linkedlist
 *
 * \param pArrayListEmployee LinkedList* receive the linkedlist
 * \return int return (1) ok
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief list all linkedlist employees
 *
 * \param pArrayListEmployee LinkedList* receive the linkedlist
 * \return int return (1) ok
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief sort all linkedlist employees
 *
 * \param pArrayListEmployee LinkedList* receive the linkedlist
 * \param order int receive the order
 * \return int return (1) ok
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee, int order);

/** \brief saves changes made to employees in a text file
 *
 * \param path char* receive the name file
 * \param pArrayListEmployee LinkedList* receive the linkedlist
 * \return int return (1) ok
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief saves changes made to employees in a binary file
 *
 * \param path char* the name file
 * \param pArrayListEmployee LinkedList* receive the linkedlist
 * \return int return (1) ok
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief generate an auto incremental id
 *
 * \param pArrayListEmployee LinkedList* receive the linkedlist
 * \return int return (1) ok
 *
 */
int generarIDempleado(LinkedList* pArrayListEmployee);


