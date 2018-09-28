typedef struct
{
    int idUsuario;
    char nombre[50];
    int idSerie;
    int estado;
}eUsuario;

void inicializarUsuariosEstado(eUsuario[], int);
void inicializarUsuariosHardCode(eUsuario[]);
void mostrarUsuario (eUsuario );
void mostrarListaUsuarios(eUsuario[], int);
int obtenerEspacioLibre(eUsuario [],int );
void altaUs (eUsuario [], int);
void bajaUsuario (eUsuario [], int );
int buscarIdUsuario(eUsuario [], int ,int );
void modificarUsuario (eUsuario [], int );
