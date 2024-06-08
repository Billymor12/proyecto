#include <iostream>

using namespace std;


#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

struct Estudiante {
    string carne;
    string nombre;
    int edad;
    char sexo;
    int matematica;
    int ciencias;
    int computacion;
    int fisica;
    int idioma;
    int literatura;
};

int main() {
    vector<Estudiante> estudiantes = {
        {"18-00001", "Juan López", 19, 'M', 73, 65, 78, 91, 82, 73},
        {"18-00002", "Carlos Suarez", 20, 'M', 54, 61, 67, 42, 69, 70},
        {"18-00003", "Karla Sánchez", 18, 'F', 90, 88, 85, 78, 94, 79},
        {"18-00004", "Ana Perez", 19, 'F', 35, 58, 63, 67, 61, 52},
        {"18-00005", "José Juárez", 22, 'M', 62, 59, 68, 62, 65, 71},
        {"18-00006", "Daniel Pérez", 21, 'M', 67, 75, 86, 76, 72, 86},
        {"18-00007", "Deina Ovando", 19, 'F', 57, 64, 61, 69, 71, 63},
        {"18-00008", "Orlando Xu", 17, 'M', 82, 83, 78, 75, 89, 95},
        {"18-00009", "Miguel Perez", 20, 'M', 78, 82, 72, 65, 69, 81},
        {"18-00010", "Alex Carrillo", 24, 'M', 49, 62, 69, 72, 75, 79}
    };

    int hombres = 0, mujeres = 0;
    int edad_minima = numeric_limits<int>::max();
    vector<string> estudiantes_jovenes;
    int reprobados_Carlos_Suarez = 0;
    vector<string> todos_aprobados;
    double promedio_mas_alto = 0;
    vector<string> estudiantes_promedio_alto;
    double promedio_mas_bajo = numeric_limits<double>::max();
    vector<string> estudiantes_promedio_bajo;
    double suma_matematicas = 0;
    int total_matematicas = 0;
    string hombre_mayor_promedio_MCF;
    double mayor_promedio_MCF_h = 0;
    string mujer_mayor_promedio_MCF;
    double mayor_promedio_MCF_f = 0;
    string estudiante_mas_reprobado;
    int max_reprobados = 0;
    vector<string> cursos_reprobados;

    for (const auto& est : estudiantes) {

        if (est.sexo == 'M') {
            hombres++;
        } else {
            mujeres++;
        }

        if (est.edad < edad_minima) {
            edad_minima = est.edad;
            estudiantes_jovenes.clear();
            estudiantes_jovenes.push_back(est.nombre);
        } else if (est.edad == edad_minima) {
            estudiantes_jovenes.push_back(est.nombre);
        }


        if (est.nombre == "Carlos Suarez") {
            if (est.matematica < 61) reprobados_Carlos_Suarez++;
            if (est.ciencias < 61) reprobados_Carlos_Suarez++;
            if (est.computacion < 61) reprobados_Carlos_Suarez++;
            if (est.fisica < 61) reprobados_Carlos_Suarez++;
            if (est.idioma < 61) reprobados_Carlos_Suarez++;
            if (est.literatura < 61) reprobados_Carlos_Suarez++;
        }


        if (est.matematica >= 61 && est.ciencias >= 61 && est.computacion >= 61 && est.fisica >= 61 && est.idioma >= 61 && est.literatura >= 61) {
            todos_aprobados.push_back(est.nombre);
        }

        // Calcular el promedio del estudiante
        double promedio = (est.matematica + est.ciencias + est.computacion + est.fisica + est.idioma + est.literatura) / 6.0;

        // Encontrar el estudiante con el promedio más alto
        if (promedio > promedio_mas_alto) {
            promedio_mas_alto = promedio;
            estudiantes_promedio_alto.clear();
            estudiantes_promedio_alto.push_back(est.nombre);
        } else if (promedio == promedio_mas_alto) {
            estudiantes_promedio_alto.push_back(est.nombre);
        }

        // Encontrar el estudiante con el promedio más bajo
        if (promedio < promedio_mas_bajo) {
            promedio_mas_bajo = promedio;
            estudiantes_promedio_bajo.clear();
            estudiantes_promedio_bajo.push_back(est.nombre);
        } else if (promedio == promedio_mas_bajo) {
            estudiantes_promedio_bajo.push_back(est.nombre);
        }

        // Sumar las notas de matemáticas
        suma_matematicas += est.matematica;
        total_matematicas++;

        // Encontrar el hombre y la mujer con mayor promedio en Matemáticas, Computación y Física
        double promedio_MCF = (est.matematica + est.computacion + est.fisica) / 3.0;
        if (est.sexo == 'M' && promedio_MCF > mayor_promedio_MCF_h) {
            mayor_promedio_MCF_h = promedio_MCF;
            hombre_mayor_promedio_MCF = est.nombre;
        }
        if (est.sexo == 'F' && promedio_MCF > mayor_promedio_MCF_f) {
            mayor_promedio_MCF_f = promedio_MCF;
            mujer_mayor_promedio_MCF = est.nombre;
        }

        // Encontrar el estudiante que reprobó más cursos
        int reprobados = 0;
        vector<string> cursos;
        if (est.matematica < 61) {
            reprobados++;
            cursos.push_back("Matemática");
        }
        if (est.ciencias < 61) {
            reprobados++;
            cursos.push_back("Ciencias");
        }
        if (est.computacion < 61) {
            reprobados++;
            cursos.push_back("Computación");
        }
        if (est.fisica < 61) {
            reprobados++;
            cursos.push_back("Física");
        }
        if (est.idioma < 61) {
            reprobados++;
            cursos.push_back("Idioma");
        }
        if (est.literatura < 61) {
            reprobados++;
            cursos.push_back("Literatura");
        }
        if (reprobados > max_reprobados) {
            max_reprobados = reprobados;
            estudiante_mas_reprobado = est.nombre;
            cursos_reprobados = cursos;
        }
    }

    // Imprimir resultados
    cout << "Total de hombres: " << hombres << endl;
    cout << "Total de mujeres: " << mujeres << endl;

    cout << "Estudiantes más jóvenes: ";
    for (const auto& nombre : estudiantes_jovenes) {
        cout << nombre << " ";
    }
    cout << endl;

    cout << "Carlos Suarez reprobó " << reprobados_Carlos_Suarez << " cursos." << endl;

    cout << "Estudiantes que aprobaron todos los cursos: ";
    for (const auto& nombre : todos_aprobados) {
        cout << nombre << " ";
    }
    cout << endl;

    cout << "Estudiantes con el promedio más alto: ";
    for (const auto& nombre : estudiantes_promedio_alto) {
        cout << nombre << " ";
    }
    cout << endl;

    cout << "Estudiantes con el promedio más bajo: ";
    for (const auto& nombre : estudiantes_promedio_bajo) {
        cout << nombre << " ";
    }
    cout << endl;

    cout << "Promedio de Matemáticas: " << suma_matematicas / total_matematicas << endl;

    cout << "Hombre con mayor promedio en Matemática, Computación y Física: " << hombre_mayor_promedio_MCF << endl;
    cout << "Mujer con mayor promedio en Matemática, Computación y Física: " << mujer_mayor_promedio_MCF << endl;

    cout << "Estudiante que reprobó más cursos: " << estudiante_mas_reprobado << " (" << max_reprobados << " cursos): ";
    for (const auto& curso : cursos_reprobados) {
        cout << curso << " ";
    }
    cout << endl;

    return 0;
}

