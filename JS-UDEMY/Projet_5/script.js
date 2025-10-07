class Personnage {
    constructor(pseudo, classe, sante, attaque, niveau){
        this.pseudo = pseudo;
        this.classe = classe;
        this.sante = sante;
        this.attaque = attaque;
        this.niveau = niveau;
    }

    evoluer() { 
        this.niveau++;
        console.log(this.pseudo + " passe au niveau " + this.niveau + " !");
    }
    verifierSante() {
        if(this.sante <= 0) {
            this.sante = 0;
            console.log(this.pseudo + " est mort !");
        }
        else if (this.sante < 0) {
            this.sante = this.sante;
        }
    }
    
    get informations() {
        return this.pseudo + " (" + this.classe + ") - " + this.sante + " points de vie - niveau " + this.niveau;
    }
}

class Magicien extends Personnage {
    constructor(pseudo) {
        super(pseudo, "Magicien", 170, 90, 1);
    }

    attaquer(personnage) {
        if(this.sante <= 0) {
            console.log(this.pseudo + " ne peut pas attaquer car il est mort...");
            return;
        }
        personnage.sante -= this.attaque;
        console.log(this.pseudo + " attaque " + personnage.pseudo + " en lançant un sort (" + this.attaque + " points de dégâts)");

        this.evoluer();

        personnage.verifierSante();
        if(personnage.sante > 0) {
            console.log(personnage.pseudo + " a " + personnage.sante + " points de vie");
        }
        else if (personnage.sante <= 0) {
            console.log(this.pseudo + " a tué " + personnage.pseudo + " !");
        }
    }

    coupSpecial(personnage) {
        if(this.sante <= 0) {
            console.log(this.pseudo + " ne peut pas attaquer car il est mort...");
            return;
        }
        personnage.sante -= this.attaque * 5;
        console.log(this.pseudo + " attaque " + personnage.pseudo + " avec son coup spécial ( " + this.attaque * 5 + " points de dégâts)");

        this.evoluer();

        personnage.verifierSante();
        if(personnage.sante > 0) {
            console.log(personnage.pseudo + " a " + personnage.sante + " points de vie");
        }
        else if (personnage.sante <= 0) {
            console.log(this.pseudo + " a tué " + personnage.pseudo + " !");
        }
    }
}

class Guerrier extends Personnage {
    constructor(pseudo) {
        super(pseudo, "Guerrier", 350, 50, 1);
    }

    attaquer(personnage) {
        if(this.sante <= 0) {
            console.log(this.pseudo + " ne peut pas attaquer car il est mort...");
            return;
        }
        personnage.sante -= this.attaque;
        console.log(this.pseudo + " attaque " + personnage.pseudo + " avec son épée (" + this.attaque + " points de dégâts)");

        this.evoluer();

        personnage.verifierSante();
        if(personnage.sante > 0) {
            console.log(personnage.pseudo + " a " + personnage.sante + " points de vie");
        }
        else if (personnage.sante <= 0) {
            console.log(this.pseudo + " a tué " + personnage.pseudo + " !");
        }
    }

    coupSpecial(personnage) {
        if(this.sante <= 0) {
            console.log(this.pseudo + " ne peut pas attaquer car il est mort...");
            return;
        }
        personnage.sante -= this.attaque * 5;
        console.log(this.pseudo + " attaque " + personnage.pseudo + " avec son coup spécial ( " + this.attaque * 5 + " points de dégâts)");
        
        this.evoluer();
        
        personnage.verifierSante();
        if(personnage.sante > 0) {
            console.log(personnage.pseudo + " a " + personnage.sante + " points de vie");
        }

        else if (personnage.sante <= 0) {
            console.log(this.pseudo + " a tué " + personnage.pseudo + " !");
        }
    }
}



var gandalf = new Magicien('Gandalf');
var thor    = new Guerrier('Thor');
console.log(thor.informations);
console.log(gandalf.informations);
gandalf.attaquer(thor);
console.log(thor.informations);
thor.attaquer(gandalf);
console.log(gandalf.informations);
gandalf.coupSpecial(thor);