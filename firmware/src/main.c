#include <asf.h>

#include "gfx_mono_ug_2832hsweg04.h"
#include "gfx_mono_text.h"
#include "sysfont.h"

#include "mc.h"
#include "hp.h"


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
		
		  for (int thisNote = 0; thisNote < hp_notes * 2; thisNote = thisNote + 2) {
			  // calculates the duration of each note
			  divider = hp_melody[thisNote + 1];
			  noteDuration = (hp_wholenote) / abs(divider);
			  if (divider < 0) {
				  noteDuration *= 1.5; // increases the duration in half for dotted notes
			  }
			  // we only play the note for 90% of the duration, leaving 10% as a pause
			  tone(hp_melody[thisNote], noteDuration * 0.9);
			  // Wait for the specief duration before playing the next note.
			  delay_ms(noteDuration*0.1);
		}

	}
}
