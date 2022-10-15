# Review

Ça compile et les résultats attendus sont obtenus.

En revanche, la partie is prime n'est pas optimale. Il est possible de faire mieux en utilisant la fonction `std::sqrt` et en ne testant que les nombres impairs.

Aussi, la technique de Miller-Rabin peut être une bonne idée pour tester la primalité d'un nombre.
Il s'agit d'une technique probabiliste qui permet de tester la primalité d'un nombre avec une forte probabilité. Elle est plus rapide que la méthode naïve et permet de tester la primalité de nombres très grands.
