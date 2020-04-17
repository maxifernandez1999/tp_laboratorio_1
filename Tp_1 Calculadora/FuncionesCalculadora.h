
/** \brief suma dos numeros ingresados
 *
 * \param num1 float primer numero ingresado por el usuario
 * \param num2 float segundo numero ingresado por el usuario
 * \return float el resultado de la suma
 *
 */
float getSuma(float num1, float num2);


/** \brief resta dos numeros ingresados
 *
 * \param num1 float primer numero ingresado por el usuario
 * \param num2 float segundo numero ingresado por el usuario
 * \return float el resultado de la resta
 *
 */
float getResta(float num1, float num2);


/** \brief multiplica dos numeros ingresados
 *
 * \param num1 float primer numero ingresado por el usuario
 * \param num2 float segundo numero ingresado por el usuario
 * \return float el resultado de la multiplicacion
 *
 */
float getMultiplicacion(float num1, float num2);


/** \brief divide dos numeros ingresados
 *
 * \param num1 float primer numero ingresado por el usuario
 * \param num2 float segundo numero ingresado por el usuario
 * \return float el resultado de la division
 *
 */
float getDivision(float num1, float num2);


/** \brief calcula el factorial del primer numero ingresado
 *
 * \param num1 int primer numero ingresado por el usuario
 * \return int el resultado del factorial
 *
 */
int getFactorialA(int i);


/** \brief calcula el factorial del segundo numero ingresado
 *
 * \param num2 int segundo numero ingresado por el usuario
 * \return int el resultado del factorial
 *
 */
int getFactorialB(int j);


/** \brief muestra el menu de opcion
 *
 * \param num1 float primer numero ingresado por el usuario
 * \param num2 float segundo numero ingresado por el usuario
 * \return void
 *
 */
void menuOpciones(float num1, float num2);


/** \brief muestra el resultado de la division si el divisor es distinto de 0, sino muestra mensaje de error
 *
 * \param num1 float primer numero ingresado
 * \param num2 float segundo numero ingresado
 * \param resultado float resultado de la division
 * \return void
 *
 */
void mostrarDivision(float num1, float num2, float resultado);


/** \brief muestra el resultado del factorial del primer numero ingresado si el numero ingresado es entero y positivo
 *
 * \param num1 float primer numero ingresado
 * \param resultadoFac long int resultado del factorial del primer numero
 * \return void
 *
 */
void mostrarFactorialA(float num1, long int resultadoFac);


/** \brief muestra el resultado del factorial del segundo numero ingresado si el numero ingresado es entero y positivo
 *
 * \param num2 float segundo numero ingresado
 * \param resultadoFacB long int resultado del factorial del segundo numero
 * \return void
 *
 */
void mostrarFactorialB(float num2, long int resultadoFacB);


/** \brief muestra si la opcion ingresada es valida, en caso de no serlo, muestra mensaje de error
 *
 * \param op int opcion ingresado por el usuario
 * \return void
 *
 */
void validarOpcion(int op);


