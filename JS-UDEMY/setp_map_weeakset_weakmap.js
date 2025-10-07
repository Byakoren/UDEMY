// Voici une fiche technique résumant l'ensemble des fonctions liées aux objets Set, Map, WeakSet et WeakMap.


// L'objet Set

// Créer un objet Set

    let monSet = new Set();
    // ou
    let monSet2 = new Set(['un', 'deux', 'trois']);

// Ajouter un élément

    monSet.add('quatre');

// Supprimer un élément

    monSet.delete('quatre');

// Supprimer tous les éléments

    monSet.clear();

// Avoir la taille de l'objet (le nombre d'éléments)

    monSet.size;

// Vérifier si un élément existe (renvoie donc true ou false)

    monSet.has('un');

// Retourner tous les éléments

    monSet.values();
    // ou
    monSet.keys();


// L'objet Map

// Créer un objet Map

    let monMap = new Map();

// Ajouter un élément

    monMap.set('John Doe', {
        email: 'john@doe.com',
    });

// Supprimer un élément

    monMap.delete('John Doe');

// Supprimer tous les éléments

    monMap.clear();

// Vérifier si un élément existe (renvoie donc true ou false)

    monMap.has('John Doe');

// Retourner un élément

    monMap.get('John Doe');

// Retourner tous les éléments

    monMap.values();
    // ou
    monMap.keys();


// L'objet WeakSet

// Créer un objet WeakSet

    let monWeakSet = new WeakSet();
    // ou
    let monWeakSet2 = new WeakSet([objet1, objet2, objet3]);

// Ajouter un élément

    monWeakSet.add(objet4);

// Supprimer un élément

    monWeakSet.delete(objet4);

// Avoir la taille de l'objet (le nombre d'éléments)

    // WeakSet n'a pas de propriété length ou size

// Vérifier si un élément existe (renvoie donc true ou false)

    monWeakSet.has(objet4);


// L'objet WeakMap

// Créer un objet WeakMap

    let monWeakMap = new WeakMap();

// Ajouter un élément

    const objet1 = {
        nom: 'John Doe',
    }
     
    monWeakMap.set(objet1, {
        email: 'john@doe.com',
    });

// Supprimer un élément

    monWeakMap.delete(objet1);

// Avoir la taille de l'objet (le nombre d'éléments)

    // WeakMap n'a pas de propriété length ou size

// Vérifier si un élément existe (renvoie donc true ou false)

    monWeakMap.has(objet1);

// Retourner un élément

    monWeakMap.get(objet1);