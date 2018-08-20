#include "DonneesCarrefour.h"

void Carrefour::loadExemple(int n){
    switch (n){
    case 1:
        // Lignes
        const LigneDeFeu arrLignes[] = { LigneDeFeu(false, true, 0),
                                         LigneDeFeu(true, true, 5),
                                         LigneDeFeu(true, true, 5),
                                         LigneDeFeu(true, false, 0),
                                         LigneDeFeu(true, false, 0),
                                         LigneDeFeu(true, true, 5),
                                         LigneDeFeu(true, true, 5),
                                         LigneDeFeu(true, false, 0),
                                         LigneDeFeu(true, false, 0),
                                         LigneDeFeu(true, true, 5) };

        _lignes = Vecteur<LigneDeFeu>(arrLignes, sizeof(arrLignes)/sizeof(arrLignes[0]));

        // Phases
        const Phase arrPhases[] = { Phase(0, "FFFTTFFTTF", 14, 41, 60, false, 2, false, true, 4, -1),
                                    Phase(1, "TTFFFFFFFT", 4, 4, 30, true, 1, true, false, 4, 15),
                                    Phase(2, "FTTFFTTFFT", 11, 15, 40, false, 0, false, true, 4, -1),
                                    Phase(3, "TFFTFFFTFF", 4, 4, 30, true, 1, true, false, 4, 15) };
        const size_t numPhases = sizeof(arrPhases)/sizeof(arrPhases[0]);
        _phases =  Vecteur<Phase>(arrPhases, numPhases);

        // Interphases
        const unsigned int dureeInterphases[numPhases][numPhases] = { {0, 7, 7, 5},
                                                                      {8, 0, 7, 0},
                                                                      {8, 8, 0, 8},
                                                                      {5, 0, 7, 0} };
        _interphases = Matrice<Interphase>(numPhases, numPhases);
        for (size_t i=0; i!=numPhases; ++i)
            for (size_t j=0; j!=numPhases; ++j)
                _interphases.element(i,j) = Interphase(i, j, dureeInterphases[i][j]);

        // Demandes Priorite
        const DemandePriorite arrDemandes[] = { DemandePriorite(13,1),
                                                DemandePriorite(33,1),
                                                DemandePriorite(92,1),
                                                DemandePriorite(25,2),
                                                DemandePriorite(64,2) };
        _demandes =  Vecteur<DemandePriorite>(arrDemandes, sizeof(arrDemandes)/sizeof(arrDemandes[0]) );

        // Phase Actuelle
        _phaseActuelle = &_phases[0];

        // Temps Ecoul�
        _tempsEcoule = 5;

        break;
    }
}


