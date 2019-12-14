
#define LED_A1  10
#define LED_B1  12
#define LED_B2  11
#define LED_C1  7
#define LED_C2  8
#define LED_C3  9
#define LED_D1  3 
#define LED_D2  4
#define LED_D3  5
#define LED_D4  6

#define MIN_LED   3
#define MAX_LED   12

int g_all[] = { 
  LED_A1, 
  LED_B1, 
  LED_B2,
  LED_C1, 
  LED_C2, 
  LED_C3, 
  LED_D1,
  LED_D2, 
  LED_D3,
  LED_D4  
};
#define ALL_LEN 10 

int g_row_a[] = {
  LED_A1
};
#define ROW_A_LEN 1

int g_row_b[] = { 
  LED_B1,
  LED_B2
};
#define ROW_B_LEN 2

int g_row_c[] = {
  LED_C1, 
  LED_C2, 
  LED_C3
};
#define ROW_C_LEN 3

int g_row_d[] = {
  LED_D1, 
  LED_D2, 
  LED_D3, 
  LED_D4
};
#define ROW_D_LEN 4

void led_group(int *p, int len, int val, int delay_len) {
  for (int i = 0; i < len; i++) {
    digitalWrite(p[i], val);
    if (delay_len > 0) {
      delay(delay_len);
    }
  }
}

int normalize(int val, int max) {
  if (val >= max) {
    val = val - max;  
  }
  return val;
}

#define CLEAR led_group(g_all, ALL_LEN, LOW, 0);

int g_orbit[] = {
  LED_A1, 
  LED_B2, 
  LED_C3, 
  LED_D4, 
  LED_D3, 
  LED_D2, 
  LED_D1,
  LED_C1,
  LED_B1,
};
#define ORBIT_LEN 9

void orbit() {
  int index = 0;
  for (int loops = 0; loops < 14; ) {
    CLEAR;
    if (loops % 2 == 1) {
      digitalWrite(LED_C2, HIGH); 
    } else {
      digitalWrite(LED_C2, LOW);
    }
    int pos = index; 
    digitalWrite(g_orbit[pos], HIGH);
    pos = normalize(pos + 1, ORBIT_LEN); 
    digitalWrite(g_orbit[pos], HIGH);
    delay(50);
    index = normalize(index + 1, ORBIT_LEN);
    if (index == 0) {
      loops++;
    }
  }
}

int g_snake[] = {
  LED_A1, 
  LED_B1, 
  LED_B2, 
  LED_C3, 
  LED_C2, 
  LED_C1, 
  LED_D1, 
  LED_D2, 
  LED_D3, 
  LED_D4  
};
#define SNAKE_LEN 10

void snake() {
  led_group(g_snake, SNAKE_LEN, HIGH, 150);
  delay(1000);
  led_group(g_snake, SNAKE_LEN, LOW, 150);
}

void snowfall() {
  int frame = 50;
  for (int loops = 0; loops < 15; loops++) {
    led_group(g_row_a, ROW_A_LEN, HIGH, 0); 
    delay(frame);
    led_group(g_row_d, ROW_D_LEN, LOW, 0); 
    delay(frame);
    led_group(g_row_b, ROW_B_LEN, HIGH, 0); 
    delay(frame);
    led_group(g_row_a, ROW_A_LEN, LOW, 0); 
    delay(frame);
    led_group(g_row_c, ROW_C_LEN, HIGH, 0);         
    delay(frame);
    led_group(g_row_b, ROW_B_LEN, LOW, 0); 
    delay(frame);
    led_group(g_row_d, ROW_D_LEN, HIGH, 0);         
    delay(frame); 
    led_group(g_row_c, ROW_C_LEN, LOW, 0); 
    delay(frame);
  }
}

int g_pwm[] = {
  LED_D1,
  LED_D4 
};
#define PWM_LEN 4

int g_not_pwm[] = {
  LED_B1,
  LED_D2, 
  LED_C2,
  LED_A1,
  LED_B2, 
  LED_C1, 
  LED_D3,  
  LED_C3
};
#define NOT_PWM_LEN 8

void fade() {
  for (int bright = 0; bright < 255; bright++) {
    for (int i = 0; i < PWM_LEN; i++) {
      analogWrite(g_pwm[i], bright);  
    }
    delay(10);
  }
  led_group(g_not_pwm, NOT_PWM_LEN, HIGH, 75);
  delay(1000);
  for (int bright = 255; bright >= 0; bright--) {
    for (int i = 0; i < PWM_LEN; i++) {
      analogWrite(g_pwm[i], bright);  
    }
    delay(10);
  }
  delay(1000);
  led_group(g_not_pwm, NOT_PWM_LEN, LOW, 75);
}

int g_hide_n_seek[] = {
  LED_D2, 
  LED_B2, 
  LED_C3, 
  LED_D1,
  LED_A1, 
  LED_C2, 
  LED_D3, 
  LED_B1, 
  LED_D4,
  LED_C1, 
};
#define HIDE_N_SEEK_LEN 9

void hide_n_seek() {
  for (int i = 0; i < HIDE_N_SEEK_LEN; i++) {
    digitalWrite(g_hide_n_seek[i], HIGH);
    delay(200);
    digitalWrite(g_hide_n_seek[i], LOW);
    delay(700);
  }
}

int g_radiate_1[] = {
  LED_C2
};
#define RADIATE_1_LEN 1

int g_radiate_2[] = {
  LED_B1,
  LED_B2, 
  LED_D2, 
  LED_D3
};
#define RADIATE_2_LEN 4

int g_radiate_3[] = {
  LED_C1, 
  LED_C3
};
#define RADIATE_3_LEN 2

int g_radiate_4[] = { 
  LED_A1, 
  LED_D1,
  LED_D4
};
#define RADIATE_4_LEN 3 

void radiate() {
  int frame = 100;
  for (int loops = 0; loops < 10; loops++) {
    for (int v = 1; v >= 0; v--) {
      led_group(g_radiate_1, RADIATE_1_LEN, v, 0);
      delay(frame);
      led_group(g_radiate_2, RADIATE_2_LEN, v, 0);
      delay(frame);
      led_group(g_radiate_3, RADIATE_3_LEN, v, 0);
      delay(frame);
      led_group(g_radiate_4, RADIATE_4_LEN, v, 0);
      delay(frame);
    }
  }
}

void blink() {
  int frame = 1000;
  for (int loops = 0; loops < 4; loops++) {
    led_group(g_all, ALL_LEN, HIGH, 0);
    delay(frame);
    led_group(g_all, ALL_LEN, LOW, 0);
    if (loops != 3) {
      delay(frame);
    }
  }
}

int g_bolt_1[] = {
  LED_A1, 
  LED_B1, 
  LED_C2, 
  LED_D2, 
  LED_D3
};
#define BOLT_1_LEN 5

int g_bolt_2[] = {
  LED_A1, 
  LED_B1, 
  LED_C1, 
  LED_C2,
  LED_D2
};
#define BOLT_2_LEN 5

int g_bolt_3[] = {
  LED_A1, 
  LED_B2, 
  LED_C3, 
  LED_C2,
  LED_D3
};
#define BOLT_3_LEN 5

void lightning(int *g_bolt, int len) {
  led_group(g_bolt, len, HIGH, 0);
  delay(100);
  led_group(g_bolt, len, LOW, 0);
  delay(50);
  led_group(g_bolt, len, HIGH, 0);
  delay(150);
  led_group(g_bolt, len, LOW, 0);
  delay(50);
  led_group(g_bolt, len, HIGH, 0);
  delay(75); 
  CLEAR;
}
  
void storm() {
  lightning(g_bolt_1, BOLT_1_LEN);
  delay(1000);
  lightning(g_bolt_2, BOLT_2_LEN);
  delay(750);
  lightning(g_bolt_3, BOLT_3_LEN);
}

void order_test() {
  led_group(g_all, ALL_LEN, HIGH, 500);  
  led_group(g_all, ALL_LEN, LOW, 0);  
}

typedef void (*anim)(void); 

anim schedule[] = {
  &snowfall, 
  &fade, 
  &orbit,
  &snake,
  &radiate, 
  &hide_n_seek,
  &blink,
  &storm
};
#define SCHEDULE_LEN 8

void setup() {
  Serial.begin(9600);
  for (int i = MIN_LED; i <= MAX_LED; i++) {
   pinMode(i, OUTPUT); 
  }
}

void loop() {
  for (int i = 0; i < SCHEDULE_LEN; i++) {
    schedule[i]();
    CLEAR; 
    delay(500);
  }
}
