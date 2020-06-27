#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief creates a dynamic memory space
 *
 * \return Employee* returns a pointer to the created memory space
 *
 */
Employee* employee_new();

/** \brief creates a dynamic memory space with parameters
 *
 * \param  char* receive a pointer to id
 * \param  char* receive a pointer to nombre
 * \param  char* receive a pointer to horasTrabajadas
 * \param  char* receive a pointer to sueldo
 * \return Employee* return a pointer to the created memory space
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);

/** \brief remove an employee
 *
 * \return void
 *
 */
void employee_delete();

/** \brief saves a variable per parameter in the structure
 *
 * \param Employee Employee* receive the structure employee
 * \param id int receive id
 * \return int return (1) ok, error (0)
 *
 */
int employee_setId(Employee* Employee,int id);

/** \brief gets a value from the structure and returns it by parameter
 *
 * \param Employee Employee* receive the structure employee
 * \param id int* receive a pointer to id
 * \return int return (1) ok, error (0)
 *
 */
int employee_getId(Employee* Employee,int* id);

/** \brief saves a variable per parameter in the structure
 *
 * \param Employee Employee* receive the structure employee
 * \param nombre char* receive a pointer to name
 * \return int return (1) ok, error (0)
 *
 */
int employee_setNombre(Employee* Employee,char* nombre);

/** \brief gets a value from the structure and returns it by parameter
 *
 * \param Employee Employee* receive the structure employee
 * \param nombre char* receive a pointer to name
 * \return int return (1) ok, error (0)
 *
 */
int employee_getNombre(Employee* Employee,char* nombre);

/** \brief saves a variable per parameter in the structure
 *
 * \param Employee Employee* receive the structure employee
 * \param horasTrabajadas int receive a pointer to horasTrabajadas
 * \return int return (1) ok, error (0)
 *
 */
int employee_setHorasTrabajadas(Employee* Employee,int horasTrabajadas);

/** \brief gets a value from the structure and returns it by parameter
 *
 * \param Employee Employee* receive the structure employee
 * \param horasTrabajadas int* recieve horasTrabajadas
 * \return int return (1) ok, error (0)
 *
 */
int employee_getHorasTrabajadas(Employee* Employee,int* horasTrabajadas);

/** \brief saves a variable per parameter in the structure
 *
 * \param Employee Employee* receive the structure employee
 * \param sueldo int receive a pointer to sueldo
 * \return int return (1) ok, error (0)
 *
 */
int employee_setSueldo(Employee* Employee,int sueldo);

/** \brief gets a value from the structure and returns it by parameter
 *
 * \param Employee Employee* receive the structure employee
 * \param sueldo int* receive sueldo
 * \return int return (1) ok, error (0)
 *
 */
int employee_getSueldo(Employee* Employee,int* sueldo);

/** \brief sorting criteria by name
 *
 * \param e1 Employee* receive an item 1
 * \param e2 Employee* receive an item 2
 * \return int returns if I can order or not
 *
 */
int employee_CompareByName(void* e1, void* e2);

/** \brief sorting criteria by id
 *
 * \param e1 Employee* receive an item 1
 * \param e2 Employee* receive an item 2
 * \return int returns if I can order or not
 *
 */
int employee_CompareById(void* e1, void* e2);

#endif // employee_H_INCLUDED

