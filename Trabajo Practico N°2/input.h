/** \brief receives an integer entered by the user and validates it
 *
 * \param message[] char receive a message
 * \param errorMessage[] char receive a error message
 * \param int receive a min value
 * \param int receive a max value
 * \return int the integer validate
 *
 */
int getInt(char [], char [], int , int );

/** \brief receives a floating number entered by the user and validates it
 *
 * \param message[] char receive a message
 * \param errorMessage[] char receive a error message
 * \param int receive a min value
 * \param int receive a max value
 * \return float the floating number validate
 *
 */
float getFloat(char [], char [], int , int );

/** \brief receives a character entered by the user and validates it
 *
 * \param message[] char  receive a message
 * \param errorMessage[] char receive a error message
 * \param char receive a min value
 * \param char receive a max value
 * \return char the character validate
 *
 */
char getCharacter(char [], char [], char , char );

/** \brief receives a string entered by the user
 *
 * \param [] char receive a message
 * \param [] char receive the string
 * \return void
 *
 */
void getString(char [], char []);

/** \brief initializes an ID to 0 and adds it to the counter
 *
 * \param int receive the counter
 * \return int return accumalator ID
 *
 */
int getId(int );


