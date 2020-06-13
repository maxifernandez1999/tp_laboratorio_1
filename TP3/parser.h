/** \brief read the text file and save it in a variable of type Employee
 *
 * \param  FILE* receive the archive
 * \param  LinkedList* receive the linkedlist
 * \return int returns if it could be read
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief read the binary file and save it in a variable of type Employee
 *
 * \param  FILE* receive the archive
 * \param  LinkedList* receive the linkedlist
 * \return int returns if it could be read
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
