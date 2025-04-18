    
# day 1
## parcours élément liste
```cpp
std::vector<int> a;
for(int x: a){

}
```

## lambda calcul for the sum simple
```cpp   
#include <numeric> // Pour std::transform_reduce

// calcule la somme de la différence absolue entre les éléments de a et de b 
auto sum = std::transform_reduce(
    a.begin(), a.end(), b.begin(), 0ULL, std::plus<>(), 
    [](int x, int y) {return static_cast<size_t>(std::abs(x - y)); }  
);
```



std::transform_reduce :
    Cette fonction prend plusieurs arguments :
        Les itérateurs de début et de fin de la première séquence (a.begin(), a.end()).
        L'itérateur de début de la deuxième séquence (b.begin()).
        Une valeur initiale pour la réduction (0ULL).
        Une opération de réduction (std::plus<>()).
        Une opération de transformation (la lambda [](int x, int y) { return static_cast<size_t>(std::abs(x - y)); }).

0ULL est la valeur initiale pour la réduction. ULL signifie "unsigned long long", ce qui garantit que la somme sera de type size_t.

std::plus<>() est un objet fonctionnel qui effectue l'addition. Il est utilisé pour accumuler les résultats de la transformation.

Fonctionnement détaillé
    Transformation :
        Pour chaque paire d'éléments (a[i], b[i]), la lambda (fonction anonyme) calcule std::abs(a[i] - b[i]) et le convertit en size_t.
    Réduction :
        Les résultats de la transformation sont ensuite accumulés (additionnés) en utilisant std::plus<>().
        La valeur initiale pour cette accumulation est 0ULL.

## lambda calcul for the sum dur
```cpp
auto sum = std::transform_reduce(
    a.begin(), a.end(), 0ULL, std::plus<>(),
    [&frequency_map](int x) {return x * frequency_map[x];}
);
```

Capture par référence :
    [&freq_map] capture freq_map par référence, ce qui signifie que la lambda utilise directement l'objet freq_map existant dans la portée englobante.
    On est obligé de mettre la référence à l'argument pour pouvoir y accéder dans la fonction en temps que constante.

```cpp
[&](int x) { return static_cast<size_t>(x * frequency_map[x]); }
```
Sinon la solution:  La lambda capture frequency_map par référence non constante ([&]), ce qui permet d'utiliser l'opérateur [] sans provoquer d'erreur de compilation.

## consulter unorderer_map
```cpp
[&frequency_map](int x) {
    auto it = frequency_map.find(x);
    return (it != frequency_map.end()) ? static_cast<size_t>(x * frequency_map[x]): 0UL;}
```
Cela permet de s'assurer que la valeur existe bien dans la unorderer_map et de pas modifier la map
si la clé x n'existe pas, elle est inserée automatiquement dans la map avec une valeur par défaut (ici 0 pour int).

condition ? res1 si oui : sinon res2