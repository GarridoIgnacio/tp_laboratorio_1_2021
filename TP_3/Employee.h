#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/// @fn Employee employee_new*()
/// @brief Constructor, Asigana espacio de un puntero del tipo Employee ne memoria dinamica
///
/// @return Retorana la direccion de memoria de dicho puntero.
Employee* employee_new();

/// @fn Employee employee_newParametros*(int*, char*, int*, int*)
/// @brief Genera un nuevo empleado a la lista pidiendo los campos por punteros y haciendo un Boxing (o encapusalandolos) con los seters.
///
/// @param id un puntero a int  donde se va a guardar la direccion de memoria de id
/// @param nombreStr un puntero a char  donde se va a guardar la direccion de memoria de nombre
/// @param horasTrabajadas un puntero a int  donde se va a guardar la direccion de memoria de horas horasTrabajadas
/// @param sueldo un puntero a int  donde se va a guardar la direccion de memoria de horas sueldo
/// @return Retorana un pontero del empleado creado.
Employee* employee_newParametros(int* id,char* nombreStr,int* horasTrabajadas,int* sueldo);

/// @fn void employee_delete(Employee*)
/// @brief Libera el espacio en el heap que ocupaba dato del tipo Employee
///
/// @param peEmpleado El empleado que se desea aliminar.
void employee_delete(Employee* peEmpleado);

/// @fn int employee_setId(Employee*, int)
/// @brief Es el encargado de hacer el boxing al campo id de un empleado nuevo.
///
/// @param this Es el empleado con sucampo correspondinte a id  donde se va a encapsular.
/// @param id Es el dato que se va a encapsular pasado por parametro desde employee_newParametros.
/// @return retoran 0 si falla y 1 si es verdadero.
int employee_setId(Employee* this,int id);

/// @fn int employee_getId(Employee*, int*)
/// @brief Es el caso inverso al anterior, se encarga de hacer el unboxing al dato encapsulado en this->id
///
/// @param this lo que se va a desencapsular
/// @param id donde se guarda el dato desencapsulado para ser usado.
/// @return retoran 0 si falla y 1 si es verdadero.
int employee_getId(Employee* this,int* id);

/// @fn int employee_setNombre(Employee*, char*)
/// @brief Es el encargado de hacer el boxing al campo nombre de un empleado nuevo.
///
/// @param this Es el empleado con sucampo correspondinte a nombre  donde se va a encapsular.
/// @param nombre Es el dato que se va a encapsular pasado por parametro desde employee_newParametros.
/// @return Retoran 0 si falla y 1 si es verdadero.
int employee_setNombre(Employee* this,char* nombre);

/// @fn int employee_getNombre(Employee*, char*)
/// @brief Es el caso inverso al anterior, se encarga de hacer el unboxing al dato encapsulado en this->nombre
///
/// @param this Lo que se va a desencapsular
/// @param nombre donde se guarda el dato desencapsulado para ser usado.
/// @return retoran 0 si falla y 1 si es verdadero.
int employee_getNombre(Employee* this,char* nombre);

/// @fn int employee_setHorasTrabajadas(Employee*, int)
/// @brief Es el encargado de hacer el boxing al campo horasTrabajadas de un empleado nuevo.
///
/// @param this Es el empleado con sucampo correspondinte a horasTrabajadas  donde se va a encapsular.
/// @param horasTrabajadas Es el dato que se va a encapsular pasado por parametro desde employee_newParametros.
/// @return Retoran 0 si falla y 1 si es verdadero.
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/// @fn int employee_getHorasTrabajadas(Employee*, int*)
/// @brief es el caso inverso al anterior, se encarga de hacer el unboxing al dato encapsulado en this->horasTrabajadas
///
/// @param this Lo que se va a desencapsular
/// @param horasTrabajadas donde se guarda el dato desencapsulado para ser usado.
/// @return retoran 0 si falla y 1 si es verdadero.
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/// @fn int employee_setSueldo(Employee*, int)
/// @brief Es el encargado de hacer el boxing al campo sueldo de un empleado nuevo.
///
/// @param this Es el empleado con sucampo correspondinte a sueldo  donde se va a encapsular.
/// @param sueldo Es el dato que se va a encapsular pasado por parametro desde employee_newParametros.
/// @return retoran 0 si falla y 1 si es verdadero.
int employee_setSueldo(Employee* this,int sueldo);

/// @fn int employee_getSueldo(Employee*, int*)
/// @brief es el caso inverso al anterior, se encarga de hacer el unboxing al dato encapsulado en this->sueldo
///
/// @param this o que se va a desencapsular
/// @param sueldo donde se guarda el dato desencapsulado para ser usado.
/// @return retoran 0 si falla y 1 si es verdadero.
int employee_getSueldo(Employee* this,int* sueldo);


/// @fn int employee_OerdenarPorNombre(void*, void*)
/// @brief Ordena los empleados alfabeticamente de forma hacendente o decendente Cunado se la llama como punterp pFuncion en el ll_sort.
///
/// @param primerEmpeado Primer puntero del tipo void a castear por el tipo dato necesario
/// @param segundoEmpleado Primer puntero del tipo void a castear por el tipo dato necesario
/// @return Retoran el orden al short.
int employee_OerdenarPorNombre (void* primerEmpeado, void* segundoEmpleado);

#endif // employee_H_INCLUDED
