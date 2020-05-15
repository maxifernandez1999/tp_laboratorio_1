typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmply;
}eEmployee;


/** \brief initializes the state vector positions to 0
 *
 * \param [] eEmployee receives the employee structure
 * \param int receives the size of the structure
 * \return void
 *
 */
void initEmployees(eEmployee [], int );

/** \brief find for free space in the state array
 *
 * \param [] eEmployee receives the employee structure
 * \param int the size of the structure
 * \return int return (-1) if no other place available
 *
 */
int findFree(eEmployee [], int);

/** \brief sort employees by last name and sector
 *
 * \param [] eEmployee receives the employee structure
 * \param int the size of the structure
 * \param order int receives 2 to order in increasing order and 1 in decreasing order
 * \return void
 *
 */
void sortEmployees(eEmployee [], int , int order);

/** \brief Load Employee and change state to vector isEmply
 *
 * \param [] eEmployee receives the employee structure
 * \param int the size of the structure
 * \param int counter
 * \return int create employee (1), Space exhausted (0)
 */
int LoadEmployee(eEmployee [], int, int);

/** \brief create a employee
 *
 * \param int counter
 * \return eEmployee return employee charged
 *
 */
eEmployee createEmployee(int);

/** \brief Print all employees
 *
 * \param [] eEmployee receives the employee structure
 * \param int the size of the structure
 * \return void
 *
 */
void printEmployees(eEmployee [], int );

/** \brief Print one employees
 *
 * \param  eEmployee receives the employee structure
 * \return void
 *
 */
void printEmployee(eEmployee myEmployee);

/** \brief modify one employee by ID
 *
 * \param [] eEmployee receives the employee structure
 * \param int the size of the structure
 * \return int Successful modification (0), ID not found (-1)
 *
 */
int modifyEmployee(eEmployee [], int );

/** \brief remove one employee by ID
 *
 * \param [] eEmployee receives the employee structure
 * \param int the size of the structure
 * \return int Successful removal(0),Operation cancelled(1) or ID not found(-1)
 *
 */
int removeEmployee(eEmployee [], int );

/** \brief accumulate total wages
 *
 * \param [] eEmployee receives the employee structure
 * \param int the size of the structure
 * \return float return total wages value
 *
 */
float accumulateSalary(eEmployee [], int );

/** \brief calculate average wages
 *
 * \param [] eEmployee receives the employee structure
 * \param int the size of the structure
 * \param int counter
 * \return float return average
 *
 */
float getAverage(eEmployee [], int , int );

/** \brief calculates the number of people who exceed the maximum salary
 *
 * \param [] eEmployee
 * \param int receives the employee structure
 * \param int the size of the structure
 * \return int counter
 *
 */
int salaryExceedsAverage(eEmployee [], int , int );
