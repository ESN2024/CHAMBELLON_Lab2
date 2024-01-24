#include <system.h>
#include "altera_avalon_pio_regs.h"
#include "altera_avalon_timer_regs.h"
#include "sys/alt_irq.h"

// Déclaration et initialisation d'une variable globale 'i' à 0
unsigned int i = 0;

// Fonction de gestionnaire d'interruption du timer
static void timer_irq()
{
	// Vérifie si les 4 bits de poids faible de 'i' sont égaux à 10
	if ((i & 0xF) == 10)
	{
		i = i + 6;

		// Vérifie si les 4 bits suivants (bits 4-7) de 'i' sont égaux à 10
		if ((i & 0xF0) >> 4 == 10)
		{

			i = i + 96;

			// Vérifie si les 4 bits suivants (bits 8-11) de 'i' sont égaux à 10
			if ((i & 0xF00) >> 8 == 10)
				i = 0; // Réinitialise 'i' à 0
		}
	}

	// Écrit la valeur de 'i' dans le registre de sortie du PIO (port d'E/S parallèle)
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE, i);

	i++;

	// Reset l'interruption en écrivant 0 dans le registre de statut du timer
	IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_0_BASE, 0);
}

int main()
{
	// Enregistre la fonction 'timer_irq' comme routine d'interruption pour l'interruption du TIMER_0_IRQ
	alt_irq_register(TIMER_0_IRQ, NULL, timer_irq);

	while (1);

	return 0;
}
