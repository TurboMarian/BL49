# BL49
Wideband Lambda Controller with Bosch CJ125 and LSU 4.9 with 0-5V output and CAN-Bus Interface<br/>

### Suitable Bosch lambda probes: ###
|Bosch number  |Length overall|Comment|
|--------------|--------------|-------|
|0 258 017 025 |1000mm|Bosch motorsport part|
|0 258 017 012 |1060mm||
|0 281 004 184 |1000mm||
|0 281 004 150 |1215mm||
|0 258 017 126 |680mm|black, used by BMW after 09/2006 (1178 7561410)|
|0 258 017 029 |620mm|grey, used by BMW after 09/2006 (1178 7539124)|
|0 258 017 092 |950mm|black, used by BMW (1178 7540167)|
|0 258 017 038 |340mm|grey, used by BMW (11787537984)|
|...|||

**Probe pinout:**<br/>
|Pin#|Color|Description|Symbol|
|----|-----|--------|-----------|
|1|red|Pump current APE|IP|
|2|yellow|Virtual ground IPN|VM|
|3|white|Heater voltage H-|Uh-|
|4|grey|Heater voltaget H+|Uh+|
|5|green|Trim Resistor RT|IA|
|6|black|Nernst voltage UN|RE|

Changes:<br/>

- 29.04.2020 - Version 0.0.1 -hardware released / software still in development, needs some changes in hardware<br/>
- 27.11.2021 - Version 0.0.3 - hardware in development, some modifications in analog PSU / software for V0.0.1 can be used with this<br/>

Interactive BOM for easier hand-soldering you can download from the github (BL49/hardware/V0.0.1/bom)
or access online here: https://oelprinz.000webhostapp.com/BL49/V0.0.1/iBOM/ibom.html <br/>
Quick link to schematic: https://github.com/oelprinz-org/BL49/blob/master/hardware/V0.0.1/schematics.pdf <br/>
<img src="hardware/V0.0.1/V0.0.0_assembled.jpeg" title="Assembled Prototype">
<p align="center">
  <img src="hardware/V0.0.1/top.png" title="Top Side">
  <img src="hardware/V0.0.1/bottom.png" alt="accessibility text"><br/>
    <img src="hardware/V0.0.1/top_layer.png" title="Top Side">
  <img src="hardware/V0.0.1/bottom_layer.png" alt="accessibility text">
</p>
