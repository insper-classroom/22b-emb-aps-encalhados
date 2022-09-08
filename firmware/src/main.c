#include <asf.h>

#include "gfx_mono_ug_2832hsweg04.h"
#include "gfx_mono_text.h"
#include "sysfont.h"

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0

int melody[] = {

	// We Wish You a Merry Christmas
	// Score available at https://musescore.com/user/6208766/scores/1497501
	
	NOTE_C5,4, //1
	NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,
	NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,
	NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
	NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,
	NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8,
	NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,
	NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,

	NOTE_F5,2, NOTE_C5,4, //8
	NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,
	NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,
	NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
	NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,
	NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8,
	NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,
	NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
	NOTE_F5,2, NOTE_C5,4,

	NOTE_F5,4, NOTE_F5,4, NOTE_F5,4,//17
	NOTE_E5,2, NOTE_E5,4,
	NOTE_F5,4, NOTE_E5,4, NOTE_D5,4,
	NOTE_C5,2, NOTE_A5,4,
	NOTE_AS5,4, NOTE_A5,4, NOTE_G5,4,
	NOTE_C6,4, NOTE_C5,4, NOTE_C5,8, NOTE_C5,8,
	NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
	NOTE_F5,2, NOTE_C5,4,
	NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,
	NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,
	
	NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8, //27
	NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,
	NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8,
	NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,
	NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
	NOTE_F5,2, NOTE_C5,4,
	NOTE_F5,4, NOTE_F5,4, NOTE_F5,4,
	NOTE_E5,2, NOTE_E5,4,
	NOTE_F5,4, NOTE_E5,4, NOTE_D5,4,
	
	NOTE_C5,2, NOTE_A5,4,//36
	NOTE_AS5,4, NOTE_A5,4, NOTE_G5,4,
	NOTE_C6,4, NOTE_C5,4, NOTE_C5,8, NOTE_C5,8,
	NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
	NOTE_F5,2, NOTE_C5,4,
	NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,
	NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,
	NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
	NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,
	
	NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8,//45
	NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,
	NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
	NOTE_F5,2, NOTE_C5,4,
	NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,
	NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,
	NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
	NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,
	
	NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, //53
	NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,
	NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
	NOTE_F5,2, REST,4
};

int tempo = 140;
#define notes sizeof(melody) / sizeof(melody[0]) / 2
#define wholenote (60000 * 4) / tempo
int divider = 0, noteDuration = 0;

// Button to change the song
#define BUTCHANGE_PIO          PIOD
#define BUTCHANGE_PIO_ID       ID_PIOD
#define BUTCHANGE_PIO_IDX      28
#define BUTCHANGE_PIO_IDX_MASK (1 << BUTCHANGE_PIO_IDX)

// Button to stop or start the song
#define BUTCONTROL_PIO          PIOC
#define BUTCONTROL_PIO_ID       ID_PIOC
#define BUTCONTROL_PIO_IDX      31
#define BUTCONTROL_PIO_IDX_MASK (1 << BUTCONTROL_PIO_IDX)

// Buzzer	
#define BUZZER_PIO				PIOA
#define BUZZER_PIO_ID			ID_PIOA
#define BUZZER_PIO_IDX			6
#define BUZZER_PIO_IDX_MASK		(1 << BUZZER_PIO_IDX)



/* flag */
volatile char butchange_flag;
volatile char butcontrol_flag;


void butchange_callback(void){
	
	butchange_flag = 1;
}

void butcontrol_callback(void){
	butcontrol_flag = !butcontrol_flag;
}

void init (void){
	
	board_init();
	sysclk_init();
	delay_init();
	
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	
	pmc_enable_periph_clk(BUTCHANGE_PIO_ID);
	pmc_enable_periph_clk(BUTCONTROL_PIO_ID);
	pmc_enable_periph_clk(BUZZER_PIO_ID);
	
	//pio_set_input(BUTCHANGE_PIO, BUTCHANGE_PIO_IDX_MASK, PIO_DEFAULT);
	//pio_set_input(BUTCONTROL_PIO, BUTCONTROL_PIO_IDX_MASK, PIO_DEFAULT);
	
	pio_set_output(BUZZER_PIO, BUZZER_PIO_IDX_MASK, 0, 0, 0);
	
	//pio_pull_up(BUTCHANGE_PIO, BUTCHANGE_PIO_IDX_MASK, 1);
	//pio_pull_up(BUTCONTROL_PIO,BUTCONTROL_PIO_IDX_MASK,1);
	
	pio_configure(BUTCHANGE_PIO, PIO_INPUT, BUTCHANGE_PIO_IDX_MASK, PIO_PULLUP | PIO_DEBOUNCE);
	pio_set_debounce_filter(BUTCHANGE_PIO, BUTCHANGE_PIO_IDX_MASK, 60);
	pio_configure(BUTCONTROL_PIO, PIO_INPUT, BUTCONTROL_PIO_IDX_MASK, PIO_PULLUP | PIO_DEBOUNCE);
	pio_set_debounce_filter(BUTCONTROL_PIO, BUTCONTROL_PIO_IDX_MASK, 60);
	
	pio_handler_set(BUTCHANGE_PIO, BUTCHANGE_PIO_ID, BUTCHANGE_PIO_IDX_MASK, PIO_IT_FALL_EDGE, butchange_callback);
	pio_handler_set(BUTCONTROL_PIO, BUTCONTROL_PIO_ID, BUTCONTROL_PIO_IDX_MASK, PIO_IT_FALL_EDGE, butcontrol_callback);
	
	
	pio_enable_interrupt(BUTCHANGE_PIO, BUTCHANGE_PIO_IDX_MASK);
	pio_enable_interrupt(BUTCONTROL_PIO, BUTCONTROL_PIO_IDX_MASK);
	pio_get_interrupt_status(BUTCHANGE_PIO);
	pio_get_interrupt_status(BUTCONTROL_PIO);
	
	NVIC_EnableIRQ(BUTCHANGE_PIO_ID);
	NVIC_EnableIRQ(BUTCONTROL_PIO_ID);
	NVIC_SetPriority(BUTCHANGE_PIO_ID, 4);
	NVIC_SetPriority(BUTCONTROL_PIO_ID, 4);
}




// Funções de controle

int get_start_stop(void){
	
	if(pio_get(BUTCONTROL_PIO, PIO_INPUT, BUTCONTROL_PIO_IDX_MASK) == 0){
		return 1;
	}
	else{
		return 0;
	}
}

int get_selecao(void){
	
	if(pio_get(BUTCHANGE_PIO, PIO_INPUT, BUTCHANGE_PIO_IDX_MASK) == 0){
		return 1;
	}
	else{
		return 0;
	}
	
}

 void set_buzzer(void){
	 pio_set(BUZZER_PIO, BUZZER_PIO_IDX_MASK);
 }
 
 void clear_buzzer(void){
	 pio_clear(BUZZER_PIO, BUZZER_PIO_IDX_MASK);
 }
 
 void buzzer_test(int freq){
	 set_buzzer();
	 delay_us(freq/2);
	 clear_buzzer();
	 delay_us(freq/2);
 }
 
/**
 * freq: Frequecia em Hz
 * time: Tempo em ms que o tom deve ser gerado
 */
void tone(int freq, int time){
	
	if(freq!=0){
		double period = (1.0/freq)*1e6;
		double pulses = time*freq/1e3;
	
		for(int i = 0; i < pulses; i++){
			if(butcontrol_flag == 1){
				break;
			}
				set_buzzer();
				delay_us(period/2);
				clear_buzzer();
				delay_us(period/2);
		}
	} else {
		set_buzzer();
		delay_ms(time);
	}

}
 

 
int main (void)
{
	init();

  // Init OLED
	gfx_mono_ssd1306_init();
  
  // Escreve na tela um circulo e um texto
	gfx_mono_draw_filled_circle(20, 16, 16, GFX_PIXEL_SET, GFX_WHOLE);
	gfx_mono_draw_string("mundo", 50,16, &sysfont);

  /* Insert application code here, after the board has been initialized. */
	while(1) {
		
		  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
			  // calculates the duration of each note
			  divider = melody[thisNote + 1];
			  noteDuration = (wholenote) / abs(divider);
			  if (divider < 0) {
				  noteDuration *= 1.5; // increases the duration in half for dotted notes
			  }
			  // we only play the note for 90% of the duration, leaving 10% as a pause
			  tone(melody[thisNote], noteDuration * 0.9);
			  // Wait for the specief duration before playing the next note.
			  delay_ms(noteDuration*0.1);
		}

	}
}
