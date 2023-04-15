import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { Observable } from 'rxjs';

import { IMqttMessage, MqttModule, IMqttServiceOptions } from 'ngx-mqtt';

export const MQTT_SERVICE_OPTIONS: IMqttServiceOptions = {
  hostname: 'perfect-politician.cloudmqtt.com',
  port: 443,
  protocol: 'wss',
  path: '',
};

@NgModule({
  declarations: [AppComponent],
  imports: [
    BrowserModule,
    AppRoutingModule,
    MqttModule.forRoot({ connectOnCreate: false }),
  ],
  providers: [],
  bootstrap: [AppComponent],
})
export class AppModule {}
