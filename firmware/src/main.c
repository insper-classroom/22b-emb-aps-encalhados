#include <asf.h>

#include "gfx_mono_ug_2832hsweg04.h"
#include "gfx_mono_text.h"
#include "sysfont.h"

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

void init (void){
	
	board_init();
	sysclk_init();
	delay_init();
	
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	
	pmc_enable_periph_clk(BUTCHANGE_PIO_ID);
	pmc_enable_periph_clk(BUTCONTROL_PIO_ID);
	pmc_enable_periph_clk(BUZZER_PIO_ID);
	
	pio_set_input(BUTCHANGE_PIO, BUTCHANGE_PIO_IDX_MASK, PIO_DEFAULT);
	pio_set_input(BUTCONTROL_PIO, BUTCONTROL_PIO_IDX_MASK, PIO_DEFAULT);
	
	pio_set_output(BUZZER_PIO, BUZZER_PIO_IDX_MASK, 0, 0, 0);
	
	pio_pull_up(BUTCHANGE_PIO, BUTCHANGE_PIO_IDX_MASK, 1);
	pio_pull_up(BUTCONTROL_PIO,BUTCONTROL_PIO_IDX_MASK,1);
	
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
	
	double t = (1.0/freq)*10e6;    // perido em us
	time = time/1000;  //tempo em us
	
	for(t; t <= time; t+=t){
		set_buzzer();
		delay_us(t/2);
		clear_buzzer();
		delay_us(t/2);
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
		
		tone(5000, 2000);

	}
}
