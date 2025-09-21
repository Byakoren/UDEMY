public class ConversionDevise {
    public static void main(String[] args) {
        // Montant en euros (sans centimes)
        int montantEuros = 1500;

        // Taux de change (1 euro = 1.22 dollars)
        double tauxChange = 1.22;

        // Conversion (résultat en dollars, peut contenir des centimes)
        double montantDollars = montantEuros * tauxChange;

        // Affichage du résultat
        System.out.println(montantEuros + " euros = " + montantDollars + " dollars");
    }
}
