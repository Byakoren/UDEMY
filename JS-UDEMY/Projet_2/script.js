let monTableau = ["un", "deux", "trois", "quatre"];
monTableau.push("cinq");
// console.log(monTableau)

// console.log(monTableau[0]);

let monTableau2D = [
    ["Mark", "Jeff", "Bill"],
    ["Zuckerberg", "Bezos", "Gates"]
];

monTableau2D.splice(2, 0, ["42" ,"61", "69"] );

// console.log(monTableau2D);

let monTableauAssociatif = {
    "prenom" : "Mark",
    "nom"    : "Zuckerberg",
    "poste"  : "PDG facebook"
};

// console.log(monTableauAssociatif["poste"]);

function concatener(tableau) {

    let chaine = '';

    for (const valeur in tableau) {
        
        chaine += (valeur + ' : ' + tableau[valeur] + " \n")
    }

    console.log(chaine);
}

concatener(monTableauAssociatif);

// for (const nombre in monTableau) {
//     console.log(nombre);
    
// }

// for (const nombre of monTableau) {
//     console.log(monTableau.indexOf(nombre));
    
// }

// for (const nombre of monTableau) {
//     console.log(nombre)
// }


let listeDePays = ["France", "Belgique", "Japon", "Maroc"];

// for (const pays of listeDePays) {
//     console.log(pays);   
// }

// listeDePays.forEach(function(){
//     console.log(pays);
// });

// listeDePays.forEach(pays => console.log(pays));