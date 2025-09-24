#include <cstddef>  // NULL vagy nullptr-hoz

struct IngatlanLista {
    double area;        // terület (m²)
    double value;       // érték (Ft)
    IngatlanLista* next;
};

IngatlanLista* beszurElejere(IngatlanLista* lista, double area, double value) {
    IngatlanLista* uj = new IngatlanLista;
    uj->area  = area;
    uj->value = value;
    uj->next  = lista;
    return uj;
}

double totalArea(IngatlanLista* lista) {
    double ossz = 0.0;
    for (IngatlanLista* p = lista; p != nullptr; p = p->next) {
        ossz += p->area;
    }
    return ossz;
}

double averageArea(IngatlanLista* lista) {
    double osszArea  = 0.0;
    double osszValue = 0.0;
    for (IngatlanLista* p = lista; p != nullptr; p = p->next) {
        osszArea  += p->area;
        osszValue += p->value;
    }
    if (osszArea == 0.0)
        return 0.0;   // elkerüljük a 0-val való osztást
    return osszValue / osszArea;
}
