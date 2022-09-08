/*
 * hp.h
 *
 * Created: 08/09/2022 12:42:17
 *  Author: sarah
 */ 


#ifndef HP_H_
#define HP_H_


#include "notes.h"


int hp_melody[] = {


	// Hedwig's theme fromn the Harry Potter Movies
	// Socre from https://musescore.com/user/3811306/scores/4906610
	
	REST, 2, NOTE_D4, 4,
	NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,
	NOTE_G4, 2, NOTE_D5, 4,
	NOTE_C5, -2,
	NOTE_A4, -2,
	NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,
	NOTE_F4, 2, NOTE_GS4, 4,
	NOTE_D4, -1,
	NOTE_D4, 4,

	NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4, //10
	NOTE_G4, 2, NOTE_D5, 4,
	NOTE_F5, 2, NOTE_E5, 4,
	NOTE_DS5, 2, NOTE_B4, 4,
	NOTE_DS5, -4, NOTE_D5, 8, NOTE_CS5, 4,
	NOTE_CS4, 2, NOTE_B4, 4,
	NOTE_G4, -1,
	NOTE_AS4, 4,
	
	NOTE_D5, 2, NOTE_AS4, 4,//18
	NOTE_D5, 2, NOTE_AS4, 4,
	NOTE_DS5, 2, NOTE_D5, 4,
	NOTE_CS5, 2, NOTE_A4, 4,
	NOTE_AS4, -4, NOTE_D5, 8, NOTE_CS5, 4,
	NOTE_CS4, 2, NOTE_D4, 4,
	NOTE_D5, -1,
	REST,4, NOTE_AS4,4,

	NOTE_D5, 2, NOTE_AS4, 4,//26
	NOTE_D5, 2, NOTE_AS4, 4,
	NOTE_F5, 2, NOTE_E5, 4,
	NOTE_DS5, 2, NOTE_B4, 4,
	NOTE_DS5, -4, NOTE_D5, 8, NOTE_CS5, 4,
	NOTE_CS4, 2, NOTE_AS4, 4,
	NOTE_G4, -1,
	
};

int hp_tempo = 144;

#define hp_notes sizeof(hp_melody) / sizeof(hp_melody[0]) / 2
#define hp_wholenote (60000 * 4) / hp_tempo

#endif /* HP_H_ */