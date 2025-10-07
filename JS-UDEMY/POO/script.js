// Animal (nombreDePattes, poids)

function Animal (nombreDePattes, poids) {
    this.nombreDePattes = nombreDePattes,
    this.poids = poids
}

// Oiseau (nombreDePattes, poids, longueurDesAiles)
function Oiseau (nombreDePattes, poids, longueurDesAiles) {
    Animal.call(this, nombreDePattes, poids),
    this.longueurDesAiles = longueurDesAiles
}

// Mammifere (nombreDePattes, poids, typeDePoils)
function Mammifere (nombreDePattes, poids, typeDePoils) {
    Animal.call(this, nombreDePattes, poids),
    this.typeDePoils = typeDePoils
}

var perroquet = new Oiseau(2, 1, 0.25);
console.log(perroquet);