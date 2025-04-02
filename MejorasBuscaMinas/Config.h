// Config.h
#ifndef CONFIG_H
#define CONFIG_H

class Config
{
    public:
        Config(int filasTablero, int columnasTablero, int minasTablero, bool modoDesarrolladorTablero, int vidasTablero);
        int getfilasTablero();
        void setfilasTablero(int filasTablero);
        int getcolumnasTablero();
        void setcolumnasTablero(int columnasTablero);
        int getminasTablero();
        void setminasTablero(int minasTablero);
        bool getmodoDesarrolladorTablero();
        void setmodoDesarrolladorTablero(bool modoDesarrolladorTablero);
        int getvidasTablero();
        void setvidasTablero(int vidasTablero);  // Método modificado a void
        void menuConfiguracion();

    private:
        int filasTablero;
        int columnasTablero;
        int minasTablero;
        bool modoDesarrolladorTablero;
        int vidasTablero;
};

#endif // CONFIG_H
