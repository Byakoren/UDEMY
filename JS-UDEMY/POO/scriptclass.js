class Utilisateur {
    constructor(prenom, nom, email) {
        this.prenom = prenom;
        this.nom = nom;
        this.email = email;
    }

    // un getter permet de récupérer une propriété
    get nomComplet() {
        return this.prenom + " " + this.nom;
    }

    // un setter permet de définir une propriété
    set nomComplet(valeur) {
        [this.prenom, this.nom] = valeur.split(" "); // split divise une chaîne de caractères en tableau à partir d'un séparateur 
    }

    sePresenter() {
        console.log("Je m'appelle " + this.prenom + " " + this.nom + " et mon email est " + this.email);
    }
}

var mark = new Utilisateur("Mark", "Zuckerberg", "mark@facebook.com");

console.log(mark.nomComplet);
mark.nomComplet = "Bill Gates";
console.log(mark.nomComplet);
// class Animal {
//     constructor(nombreDePattes, poids) {
//         this.nombreDePattes = nombreDePattes;
//         this.poids = poids;
//     }

//     presentation() {
//         console.log("Je suis un animal avec " + this.nombreDePattes + " pattes et je pèse " + this.poids + ".");
//     }
// }

// class Oiseau extends Animal {
//     constructor(nombreDePattes, poids, longueurDesAiles) {
//         super(nombreDePattes, poids);
//         this.longueurDesAiles = longueurDesAiles;
//     }

//     presentation() {
//         super.presentation();
//         console.log("J'ai des ailes de " + this.longueurDesAiles + " mètres de long.");
//     }

//     voler() {
//         console.log("Je vole !");
//     }
// }

// var perroquet = new Oiseau(2, "1kg" , "grandes");
// perroquet.presentation();
// perroquet.voler();  