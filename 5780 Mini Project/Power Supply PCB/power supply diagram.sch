<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.6.2">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="SamacSys_Parts">
<description>&lt;b&gt;https://componentsearchengine.com&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by SamacSys&lt;/author&gt;</description>
<packages>
<package name="LM22678TJ50NOPB">
<description>&lt;b&gt;NDR0007A_2020&lt;/b&gt;&lt;br&gt;
</description>
<smd name="1" x="-3.81" y="-4.595" dx="2.41" dy="0.91" layer="1" rot="R90"/>
<smd name="2" x="-2.54" y="-4.595" dx="2.41" dy="0.91" layer="1" rot="R90"/>
<smd name="3" x="-1.27" y="-4.595" dx="2.41" dy="0.91" layer="1" rot="R90"/>
<smd name="4" x="0" y="-4.595" dx="2.41" dy="0.91" layer="1" rot="R90"/>
<smd name="5" x="1.27" y="-4.595" dx="2.41" dy="0.91" layer="1" rot="R90"/>
<smd name="6" x="2.54" y="-4.595" dx="2.41" dy="0.91" layer="1" rot="R90"/>
<smd name="7" x="3.81" y="-4.595" dx="2.41" dy="0.91" layer="1" rot="R90"/>
<smd name="8" x="0" y="4.595" dx="6.35" dy="5.59" layer="1" rot="R90"/>
<text x="0" y="0.76" size="1.27" layer="25" align="center">&gt;NAME</text>
<text x="0" y="0.76" size="1.27" layer="27" align="center">&gt;VALUE</text>
<wire x1="-5.08" y1="4.925" x2="5.08" y2="4.925" width="0.2" layer="51"/>
<wire x1="5.08" y1="4.925" x2="5.08" y2="-4.925" width="0.2" layer="51"/>
<wire x1="5.08" y1="-4.925" x2="-5.08" y2="-4.925" width="0.2" layer="51"/>
<wire x1="-5.08" y1="-4.925" x2="-5.08" y2="4.925" width="0.2" layer="51"/>
<wire x1="-6.08" y1="8.77" x2="6.08" y2="8.77" width="0.1" layer="51"/>
<wire x1="6.08" y1="8.77" x2="6.08" y2="-7.25" width="0.1" layer="51"/>
<wire x1="6.08" y1="-7.25" x2="-6.08" y2="-7.25" width="0.1" layer="51"/>
<wire x1="-6.08" y1="-7.25" x2="-6.08" y2="8.77" width="0.1" layer="51"/>
<wire x1="-3.2" y1="4.925" x2="-5.08" y2="4.925" width="0.1" layer="21"/>
<wire x1="-5.08" y1="4.925" x2="-5.08" y2="-4.925" width="0.1" layer="21"/>
<wire x1="3.2" y1="4.925" x2="5.08" y2="4.925" width="0.1" layer="21"/>
<wire x1="5.08" y1="4.925" x2="5.08" y2="-4.925" width="0.1" layer="21"/>
<wire x1="-4.2" y1="-6.2" x2="-4.2" y2="-6.2" width="0.1" layer="21"/>
<wire x1="-4.2" y1="-6.2" x2="-4.1" y2="-6.2" width="0.1" layer="21" curve="180"/>
<wire x1="-4.1" y1="-6.2" x2="-4.1" y2="-6.2" width="0.1" layer="21"/>
<wire x1="-4.1" y1="-6.2" x2="-4.2" y2="-6.2" width="0.1" layer="21" curve="180"/>
</package>
</packages>
<symbols>
<symbol name="LM22678TJ-5.0_NOPB">
<wire x1="5.08" y1="2.54" x2="25.4" y2="2.54" width="0.254" layer="94"/>
<wire x1="25.4" y1="-17.78" x2="25.4" y2="2.54" width="0.254" layer="94"/>
<wire x1="25.4" y1="-17.78" x2="5.08" y2="-17.78" width="0.254" layer="94"/>
<wire x1="5.08" y1="2.54" x2="5.08" y2="-17.78" width="0.254" layer="94"/>
<text x="26.67" y="7.62" size="1.778" layer="95" align="center-left">&gt;NAME</text>
<text x="26.67" y="5.08" size="1.778" layer="96" align="center-left">&gt;VALUE</text>
<pin name="SW" x="0" y="0" length="middle"/>
<pin name="VIN" x="0" y="-2.54" length="middle"/>
<pin name="BOOT" x="0" y="-5.08" length="middle"/>
<pin name="GND_1" x="0" y="-7.62" length="middle"/>
<pin name="NC" x="0" y="-10.16" length="middle" direction="nc"/>
<pin name="FB" x="0" y="-12.7" length="middle"/>
<pin name="EN" x="0" y="-15.24" length="middle"/>
<pin name="GND_2" x="30.48" y="0" length="middle" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="LM22678TJ-5.0_NOPB" prefix="IC">
<description>&lt;b&gt;SIMPLE SWITCHER 4.5V to 42V, 5A Step-Down Voltage Regulator with Precision Enable&lt;/b&gt;&lt;p&gt;
Source: &lt;a href="http://www.ti.com/lit/gpn/LM22678"&gt; Datasheet &lt;/a&gt;</description>
<gates>
<gate name="G$1" symbol="LM22678TJ-5.0_NOPB" x="0" y="0"/>
</gates>
<devices>
<device name="" package="LM22678TJ50NOPB">
<connects>
<connect gate="G$1" pin="BOOT" pad="3"/>
<connect gate="G$1" pin="EN" pad="7"/>
<connect gate="G$1" pin="FB" pad="6"/>
<connect gate="G$1" pin="GND_1" pad="4"/>
<connect gate="G$1" pin="GND_2" pad="8"/>
<connect gate="G$1" pin="NC" pad="5"/>
<connect gate="G$1" pin="SW" pad="1"/>
<connect gate="G$1" pin="VIN" pad="2"/>
</connects>
<technologies>
<technology name="">
<attribute name="DESCRIPTION" value="SIMPLE SWITCHER 4.5V to 42V, 5A Step-Down Voltage Regulator with Precision Enable" constant="no"/>
<attribute name="HEIGHT" value="2.1mm" constant="no"/>
<attribute name="MANUFACTURER_NAME" value="Texas Instruments" constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="LM22678TJ-5.0/NOPB" constant="no"/>
<attribute name="MOUSER_PART_NUMBER" value="926-LM22678TJ50NOPB" constant="no"/>
<attribute name="MOUSER_PRICE-STOCK" value="https://www.mouser.co.uk/ProductDetail/Texas-Instruments/LM22678TJ-50-NOPB?qs=X1J7HmVL2ZHigSTWjAFUig%3D%3D" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="SamacSys_Parts" urn="urn:adsk.eagle:library:27935277">
<description>&lt;b&gt;https://componentsearchengine.com&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by SamacSys&lt;/author&gt;</description>
<packages>
<package name="CAPC3216X180N" urn="urn:adsk.eagle:footprint:27935283/1" library_version="1">
<description>&lt;b&gt;C3216 (160 thickness)&lt;/b&gt;&lt;br&gt;
</description>
<smd name="1" x="-1.6" y="0" dx="1.82" dy="0.62" layer="1" rot="R90"/>
<smd name="2" x="1.6" y="0" dx="1.82" dy="0.62" layer="1" rot="R90"/>
<text x="0" y="0" size="1.27" layer="25" align="center">&gt;NAME</text>
<text x="0" y="0" size="1.27" layer="27" align="center">&gt;VALUE</text>
<wire x1="-2.06" y1="1.06" x2="2.06" y2="1.06" width="0.05" layer="51"/>
<wire x1="2.06" y1="1.06" x2="2.06" y2="-1.06" width="0.05" layer="51"/>
<wire x1="2.06" y1="-1.06" x2="-2.06" y2="-1.06" width="0.05" layer="51"/>
<wire x1="-2.06" y1="-1.06" x2="-2.06" y2="1.06" width="0.05" layer="51"/>
<wire x1="-1.6" y1="0.8" x2="1.6" y2="0.8" width="0.1" layer="51"/>
<wire x1="1.6" y1="0.8" x2="1.6" y2="-0.8" width="0.1" layer="51"/>
<wire x1="1.6" y1="-0.8" x2="-1.6" y2="-0.8" width="0.1" layer="51"/>
<wire x1="-1.6" y1="-0.8" x2="-1.6" y2="0.8" width="0.1" layer="51"/>
<wire x1="0" y1="0.7" x2="0" y2="-0.7" width="0.2" layer="21"/>
</package>
<package name="CAPC2012X100N" urn="urn:adsk.eagle:footprint:27935284/1" library_version="1">
<description>&lt;b&gt;C0805C105K4RACTU_a&lt;/b&gt;&lt;br&gt;
</description>
<smd name="1" x="-0.8" y="0" dx="1.47" dy="1.02" layer="1" rot="R90"/>
<smd name="2" x="0.8" y="0" dx="1.47" dy="1.02" layer="1" rot="R90"/>
<text x="0" y="0" size="1.27" layer="25" align="center">&gt;NAME</text>
<text x="0" y="0" size="1.27" layer="27" align="center">&gt;VALUE</text>
<wire x1="-1.46" y1="0.89" x2="1.46" y2="0.89" width="0.05" layer="51"/>
<wire x1="1.46" y1="0.89" x2="1.46" y2="-0.89" width="0.05" layer="51"/>
<wire x1="1.46" y1="-0.89" x2="-1.46" y2="-0.89" width="0.05" layer="51"/>
<wire x1="-1.46" y1="-0.89" x2="-1.46" y2="0.89" width="0.05" layer="51"/>
<wire x1="-1" y1="0.625" x2="1" y2="0.625" width="0.1" layer="51"/>
<wire x1="1" y1="0.625" x2="1" y2="-0.625" width="0.1" layer="51"/>
<wire x1="1" y1="-0.625" x2="-1" y2="-0.625" width="0.1" layer="51"/>
<wire x1="-1" y1="-0.625" x2="-1" y2="0.625" width="0.1" layer="51"/>
</package>
<package name="CAPC2012X135N" urn="urn:adsk.eagle:footprint:27935285/1" library_version="1">
<description>&lt;b&gt;0805&lt;/b&gt;&lt;br&gt;
</description>
<smd name="1" x="-0.79" y="0" dx="1.39" dy="0.96" layer="1" rot="R90"/>
<smd name="2" x="0.79" y="0" dx="1.39" dy="0.96" layer="1" rot="R90"/>
<text x="0" y="0" size="1.27" layer="25" align="center">&gt;NAME</text>
<text x="0" y="0" size="1.27" layer="27" align="center">&gt;VALUE</text>
<wire x1="-1.42" y1="0.85" x2="1.42" y2="0.85" width="0.05" layer="51"/>
<wire x1="1.42" y1="0.85" x2="1.42" y2="-0.85" width="0.05" layer="51"/>
<wire x1="1.42" y1="-0.85" x2="-1.42" y2="-0.85" width="0.05" layer="51"/>
<wire x1="-1.42" y1="-0.85" x2="-1.42" y2="0.85" width="0.05" layer="51"/>
<wire x1="-1" y1="0.625" x2="1" y2="0.625" width="0.1" layer="51"/>
<wire x1="1" y1="0.625" x2="1" y2="-0.625" width="0.1" layer="51"/>
<wire x1="1" y1="-0.625" x2="-1" y2="-0.625" width="0.1" layer="51"/>
<wire x1="-1" y1="-0.625" x2="-1" y2="0.625" width="0.1" layer="51"/>
</package>
<package name="DIOM7959X250N" urn="urn:adsk.eagle:footprint:27935282/1" library_version="1">
<description>&lt;b&gt;SMC&lt;/b&gt;&lt;br&gt;
</description>
<smd name="1" x="-3.5" y="0" dx="3.1" dy="2.2" layer="1" rot="R90"/>
<smd name="2" x="3.5" y="0" dx="3.1" dy="2.2" layer="1" rot="R90"/>
<text x="0" y="0" size="1.27" layer="25" align="center">&gt;NAME</text>
<text x="0" y="0" size="1.27" layer="27" align="center">&gt;VALUE</text>
<wire x1="-4.85" y1="3.36" x2="4.85" y2="3.36" width="0.05" layer="51"/>
<wire x1="4.85" y1="3.36" x2="4.85" y2="-3.36" width="0.05" layer="51"/>
<wire x1="4.85" y1="-3.36" x2="-4.85" y2="-3.36" width="0.05" layer="51"/>
<wire x1="-4.85" y1="-3.36" x2="-4.85" y2="3.36" width="0.05" layer="51"/>
<wire x1="-3.97" y1="2.952" x2="3.97" y2="2.952" width="0.1" layer="51"/>
<wire x1="3.97" y1="2.952" x2="3.97" y2="-2.952" width="0.1" layer="51"/>
<wire x1="3.97" y1="-2.952" x2="-3.97" y2="-2.952" width="0.1" layer="51"/>
<wire x1="-3.97" y1="-2.952" x2="-3.97" y2="2.952" width="0.1" layer="51"/>
<wire x1="-3.97" y1="1.852" x2="-2.87" y2="2.952" width="0.1" layer="51"/>
<wire x1="3.97" y1="2.952" x2="-4.6" y2="2.952" width="0.2" layer="21"/>
<wire x1="-3.97" y1="-2.952" x2="3.97" y2="-2.952" width="0.2" layer="21"/>
</package>
<package name="SDR1307-220ML" urn="urn:adsk.eagle:footprint:27935287/1" library_version="1">
<description>&lt;b&gt;SDR1307-220ML&lt;/b&gt;&lt;br&gt;
</description>
<smd name="1" x="0" y="4.625" dx="14" dy="4.75" layer="1"/>
<smd name="2" x="0" y="-4.625" dx="14" dy="4.75" layer="1"/>
<text x="0.824" y="0.068" size="1.27" layer="25" align="center">&gt;NAME</text>
<text x="0.824" y="0.068" size="1.27" layer="27" align="center">&gt;VALUE</text>
<circle x="0" y="0" radius="6.5" width="0.2" layer="51"/>
<circle x="-8.967" y="8.454" radius="0.590909375" width="1" layer="25"/>
</package>
<package name="TB00650802BE" urn="urn:adsk.eagle:footprint:27935288/1" library_version="1">
<description>&lt;b&gt;TB006-508-02BE-2&lt;/b&gt;&lt;br&gt;
</description>
<pad name="1" x="0" y="0" drill="1.3" diameter="1.95"/>
<pad name="2" x="5.08" y="0" drill="1.3" diameter="1.95"/>
<text x="2.54" y="0" size="1.27" layer="25" align="center">&gt;NAME</text>
<text x="2.54" y="0" size="1.27" layer="27" align="center">&gt;VALUE</text>
<wire x1="-2.54" y1="4.1" x2="7.62" y2="4.1" width="0.2" layer="51"/>
<wire x1="7.62" y1="4.1" x2="7.62" y2="-4.1" width="0.2" layer="51"/>
<wire x1="7.62" y1="-4.1" x2="-2.54" y2="-4.1" width="0.2" layer="51"/>
<wire x1="-2.54" y1="-4.1" x2="-2.54" y2="4.1" width="0.2" layer="51"/>
<wire x1="-2.54" y1="4.1" x2="7.62" y2="4.1" width="0.1" layer="21"/>
<wire x1="7.62" y1="4.1" x2="7.62" y2="-4.1" width="0.1" layer="21"/>
<wire x1="7.62" y1="-4.1" x2="-2.54" y2="-4.1" width="0.1" layer="21"/>
<wire x1="-2.54" y1="-4.1" x2="-2.54" y2="4.1" width="0.1" layer="21"/>
<wire x1="-3.54" y1="5.1" x2="8.62" y2="5.1" width="0.1" layer="51"/>
<wire x1="8.62" y1="5.1" x2="8.62" y2="-5.1" width="0.1" layer="51"/>
<wire x1="8.62" y1="-5.1" x2="-3.54" y2="-5.1" width="0.1" layer="51"/>
<wire x1="-3.54" y1="-5.1" x2="-3.54" y2="5.1" width="0.1" layer="51"/>
</package>
<package name="16SVPE180M" urn="urn:adsk.eagle:footprint:27935286/1" library_version="1">
<description>&lt;b&gt;C10&lt;/b&gt;&lt;br&gt;
</description>
<smd name="1" x="-2.8" y="0" dx="3.5" dy="1.6" layer="1"/>
<smd name="2" x="2.8" y="0" dx="3.5" dy="1.6" layer="1"/>
<text x="0" y="0" size="1.27" layer="25" align="center">&gt;NAME</text>
<text x="0" y="0" size="1.27" layer="27" align="center">&gt;VALUE</text>
<wire x1="-3.65" y1="3.3" x2="3.65" y2="3.3" width="0.2" layer="51"/>
<wire x1="3.65" y1="3.3" x2="3.65" y2="-3.3" width="0.2" layer="51"/>
<wire x1="3.65" y1="-3.3" x2="-3.65" y2="-3.3" width="0.2" layer="51"/>
<wire x1="-3.65" y1="-3.3" x2="-3.65" y2="3.3" width="0.2" layer="51"/>
<wire x1="-5.55" y1="4.3" x2="5.55" y2="4.3" width="0.1" layer="51"/>
<wire x1="5.55" y1="4.3" x2="5.55" y2="-4.3" width="0.1" layer="51"/>
<wire x1="5.55" y1="-4.3" x2="-5.55" y2="-4.3" width="0.1" layer="51"/>
<wire x1="-5.55" y1="-4.3" x2="-5.55" y2="4.3" width="0.1" layer="51"/>
<wire x1="-3.65" y1="1.5" x2="-3.65" y2="3.3" width="0.1" layer="21"/>
<wire x1="-3.65" y1="3.3" x2="3.65" y2="3.3" width="0.1" layer="21"/>
<wire x1="3.65" y1="3.3" x2="3.65" y2="1.5" width="0.1" layer="21"/>
<wire x1="-3.65" y1="-1.5" x2="-3.65" y2="-3.3" width="0.1" layer="21"/>
<wire x1="-3.65" y1="-3.3" x2="3.65" y2="-3.3" width="0.1" layer="21"/>
<wire x1="3.65" y1="-3.3" x2="3.65" y2="-1.5" width="0.1" layer="21"/>
</package>
<package name="CONSOCJ2155" urn="urn:adsk.eagle:footprint:27935278/1" library_version="1">
<description>&lt;b&gt;CON-SOCJ-2155_1&lt;/b&gt;&lt;br&gt;
</description>
<pad name="1" x="0" y="0" drill="3.6401" diameter="5.3"/>
<pad name="2" x="-6" y="0" drill="3.1623" diameter="5"/>
<pad name="3" x="-3" y="-4.7" drill="3.6401" diameter="5.3"/>
<text x="-5.925" y="-1.425" size="1.27" layer="25" align="center">&gt;NAME</text>
<text x="-5.925" y="-1.425" size="1.27" layer="27" align="center">&gt;VALUE</text>
<wire x1="-14.5" y1="-4.5" x2="0.7" y2="-4.5" width="0.2" layer="51"/>
<wire x1="0.7" y1="-4.5" x2="0.7" y2="4.5" width="0.2" layer="51"/>
<wire x1="0.7" y1="4.5" x2="-14.5" y2="4.5" width="0.2" layer="51"/>
<wire x1="-14.5" y1="4.5" x2="-14.5" y2="-4.5" width="0.2" layer="51"/>
<wire x1="-15.5" y1="-8.35" x2="3.65" y2="-8.35" width="0.1" layer="51"/>
<wire x1="3.65" y1="-8.35" x2="3.65" y2="5.5" width="0.1" layer="51"/>
<wire x1="3.65" y1="5.5" x2="-15.5" y2="5.5" width="0.1" layer="51"/>
<wire x1="-15.5" y1="5.5" x2="-15.5" y2="-8.35" width="0.1" layer="51"/>
<wire x1="0.7" y1="3" x2="0.7" y2="4.5" width="0.1" layer="21"/>
<wire x1="0.7" y1="4.5" x2="-14.5" y2="4.5" width="0.1" layer="21"/>
<wire x1="-14.5" y1="4.5" x2="-14.5" y2="-4.5" width="0.1" layer="21"/>
<wire x1="-14.5" y1="-4.5" x2="-6.5" y2="-4.5" width="0.1" layer="21"/>
</package>
</packages>
<packages3d>
<package3d name="CAPC3216X180N" urn="urn:adsk.eagle:package:27935305/1" type="box" library_version="1">
<description>&lt;b&gt;C3216 (160 thickness)&lt;/b&gt;&lt;br&gt;
</description>
<packageinstances>
<packageinstance name="CAPC3216X180N"/>
</packageinstances>
</package3d>
<package3d name="CAPC2012X100N" urn="urn:adsk.eagle:package:27935306/1" type="box" library_version="1">
<description>&lt;b&gt;C0805C105K4RACTU_a&lt;/b&gt;&lt;br&gt;
</description>
<packageinstances>
<packageinstance name="CAPC2012X100N"/>
</packageinstances>
</package3d>
<package3d name="CAPC2012X135N" urn="urn:adsk.eagle:package:27935307/1" type="box" library_version="1">
<description>&lt;b&gt;0805&lt;/b&gt;&lt;br&gt;
</description>
<packageinstances>
<packageinstance name="CAPC2012X135N"/>
</packageinstances>
</package3d>
<package3d name="DIOM7959X250N" urn="urn:adsk.eagle:package:27935304/1" type="box" library_version="1">
<description>&lt;b&gt;SMC&lt;/b&gt;&lt;br&gt;
</description>
<packageinstances>
<packageinstance name="DIOM7959X250N"/>
</packageinstances>
</package3d>
<package3d name="SDR1307-220ML" urn="urn:adsk.eagle:package:27935309/1" type="box" library_version="1">
<description>&lt;b&gt;SDR1307-220ML&lt;/b&gt;&lt;br&gt;
</description>
<packageinstances>
<packageinstance name="SDR1307-220ML"/>
</packageinstances>
</package3d>
<package3d name="TB00650802BE" urn="urn:adsk.eagle:package:27935310/1" type="box" library_version="1">
<description>&lt;b&gt;TB006-508-02BE-2&lt;/b&gt;&lt;br&gt;
</description>
<packageinstances>
<packageinstance name="TB00650802BE"/>
</packageinstances>
</package3d>
<package3d name="16SVPE180M" urn="urn:adsk.eagle:package:27935308/1" type="box" library_version="1">
<description>&lt;b&gt;C10&lt;/b&gt;&lt;br&gt;
</description>
<packageinstances>
<packageinstance name="16SVPE180M"/>
</packageinstances>
</package3d>
<package3d name="CONSOCJ2155" urn="urn:adsk.eagle:package:27935300/1" type="box" library_version="1">
<description>&lt;b&gt;CON-SOCJ-2155_1&lt;/b&gt;&lt;br&gt;
</description>
<packageinstances>
<packageinstance name="CONSOCJ2155"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="C3216X6S1V106K160AC" urn="urn:adsk.eagle:symbol:27935294/1" library_version="1">
<wire x1="5.588" y1="2.54" x2="5.588" y2="-2.54" width="0.254" layer="94"/>
<wire x1="7.112" y1="2.54" x2="7.112" y2="-2.54" width="0.254" layer="94"/>
<wire x1="5.08" y1="0" x2="5.588" y2="0" width="0.254" layer="94"/>
<wire x1="7.112" y1="0" x2="7.62" y2="0" width="0.254" layer="94"/>
<text x="8.89" y="6.35" size="1.778" layer="95" align="center-left">&gt;NAME</text>
<text x="8.89" y="3.81" size="1.778" layer="96" align="center-left">&gt;VALUE</text>
<pin name="1" x="0" y="0" visible="pad" length="middle"/>
<pin name="2" x="12.7" y="0" visible="pad" length="middle" rot="R180"/>
</symbol>
<symbol name="C0805C105K4RACTU" urn="urn:adsk.eagle:symbol:27935295/1" library_version="1">
<wire x1="5.588" y1="2.54" x2="5.588" y2="-2.54" width="0.254" layer="94"/>
<wire x1="7.112" y1="2.54" x2="7.112" y2="-2.54" width="0.254" layer="94"/>
<wire x1="5.08" y1="0" x2="5.588" y2="0" width="0.254" layer="94"/>
<wire x1="7.112" y1="0" x2="7.62" y2="0" width="0.254" layer="94"/>
<text x="8.89" y="6.35" size="1.778" layer="95" align="center-left">&gt;NAME</text>
<text x="8.89" y="3.81" size="1.778" layer="96" align="center-left">&gt;VALUE</text>
<pin name="1" x="0" y="0" visible="pad" length="middle"/>
<pin name="2" x="12.7" y="0" visible="pad" length="middle" rot="R180"/>
</symbol>
<symbol name="CC0805KRX7R9BB103" urn="urn:adsk.eagle:symbol:27935296/1" library_version="1">
<wire x1="5.588" y1="2.54" x2="5.588" y2="-2.54" width="0.254" layer="94"/>
<wire x1="7.112" y1="2.54" x2="7.112" y2="-2.54" width="0.254" layer="94"/>
<wire x1="5.08" y1="0" x2="5.588" y2="0" width="0.254" layer="94"/>
<wire x1="7.112" y1="0" x2="7.62" y2="0" width="0.254" layer="94"/>
<text x="8.89" y="6.35" size="1.778" layer="95" align="center-left">&gt;NAME</text>
<text x="8.89" y="3.81" size="1.778" layer="96" align="center-left">&gt;VALUE</text>
<pin name="1" x="0" y="0" visible="pad" length="middle"/>
<pin name="2" x="12.7" y="0" visible="pad" length="middle" rot="R180"/>
</symbol>
<symbol name="B540C-13-F" urn="urn:adsk.eagle:symbol:27935293/1" library_version="1">
<wire x1="5.08" y1="2.54" x2="5.08" y2="-2.54" width="0.254" layer="94"/>
<text x="11.43" y="5.08" size="1.778" layer="95" align="center-left">&gt;NAME</text>
<text x="11.43" y="2.54" size="1.778" layer="96" align="center-left">&gt;VALUE</text>
<pin name="K" x="0" y="0" visible="pad" length="middle"/>
<pin name="A" x="15.24" y="0" visible="pad" length="middle" rot="R180"/>
<polygon width="0.254" layer="94">
<vertex x="5.08" y="0"/>
<vertex x="10.16" y="2.54"/>
<vertex x="10.16" y="-2.54"/>
</polygon>
</symbol>
<symbol name="SDR1307-4R7ML" urn="urn:adsk.eagle:symbol:27935298/1" library_version="1">
<wire x1="5.08" y1="0" x2="7.62" y2="0" width="0.254" layer="94" curve="-175.4"/>
<wire x1="7.62" y1="0" x2="10.16" y2="0" width="0.254" layer="94" curve="-175.4"/>
<wire x1="10.16" y1="0" x2="12.7" y2="0" width="0.254" layer="94" curve="-175.4"/>
<wire x1="12.7" y1="0" x2="15.24" y2="0" width="0.254" layer="94" curve="-175.4"/>
<text x="16.51" y="6.35" size="1.778" layer="95" align="center-left">&gt;NAME</text>
<text x="16.51" y="3.81" size="1.778" layer="96" align="center-left">&gt;VALUE</text>
<pin name="1" x="0" y="0" visible="pad" length="middle"/>
<pin name="2" x="20.32" y="0" visible="pad" length="middle" rot="R180"/>
</symbol>
<symbol name="TB006-508-02BE" urn="urn:adsk.eagle:symbol:27935299/1" library_version="1">
<wire x1="5.08" y1="2.54" x2="15.24" y2="2.54" width="0.254" layer="94"/>
<wire x1="15.24" y1="-5.08" x2="15.24" y2="2.54" width="0.254" layer="94"/>
<wire x1="15.24" y1="-5.08" x2="5.08" y2="-5.08" width="0.254" layer="94"/>
<wire x1="5.08" y1="2.54" x2="5.08" y2="-5.08" width="0.254" layer="94"/>
<text x="16.51" y="7.62" size="1.778" layer="95" align="center-left">&gt;NAME</text>
<text x="16.51" y="5.08" size="1.778" layer="96" align="center-left">&gt;VALUE</text>
<pin name="1" x="0" y="0" length="middle"/>
<pin name="2" x="0" y="-2.54" length="middle"/>
</symbol>
<symbol name="16SVPE180M" urn="urn:adsk.eagle:symbol:27935297/1" library_version="1">
<wire x1="5.588" y1="2.54" x2="5.588" y2="-2.54" width="0.254" layer="94"/>
<wire x1="7.112" y1="2.54" x2="7.112" y2="-2.54" width="0.254" layer="94"/>
<wire x1="5.08" y1="0" x2="5.588" y2="0" width="0.254" layer="94"/>
<wire x1="7.112" y1="0" x2="7.62" y2="0" width="0.254" layer="94"/>
<text x="8.89" y="6.35" size="1.778" layer="95" align="center-left">&gt;NAME</text>
<text x="8.89" y="3.81" size="1.778" layer="96" align="center-left">&gt;VALUE</text>
<pin name="1" x="0" y="0" visible="pad" length="middle"/>
<pin name="2" x="12.7" y="0" visible="pad" length="middle" rot="R180"/>
</symbol>
<symbol name="CON-SOCJ-2155" urn="urn:adsk.eagle:symbol:27935289/1" library_version="1">
<wire x1="5.08" y1="1.016" x2="5.08" y2="-1.016" width="0.254" layer="94"/>
<wire x1="15.24" y1="-1.016" x2="5.08" y2="-1.016" width="0.254" layer="94"/>
<wire x1="15.24" y1="-1.016" x2="15.24" y2="1.016" width="0.254" layer="94"/>
<wire x1="5.08" y1="1.016" x2="15.24" y2="1.016" width="0.254" layer="94"/>
<wire x1="2.54" y1="0" x2="5.08" y2="0" width="0.254" layer="94"/>
<wire x1="2.54" y1="-2.54" x2="7.62" y2="-2.54" width="0.254" layer="94"/>
<wire x1="7.62" y1="-5.08" x2="7.62" y2="-2.54" width="0.254" layer="94"/>
<wire x1="2.54" y1="-5.08" x2="10.16" y2="-5.08" width="0.254" layer="94"/>
<wire x1="12.7" y1="-2.54" x2="10.16" y2="-5.08" width="0.254" layer="94"/>
<wire x1="12.7" y1="-2.54" x2="15.24" y2="-5.08" width="0.254" layer="94"/>
<wire x1="7.62" y1="-5.08" x2="7.112" y2="-3.556" width="0.254" layer="94"/>
<wire x1="8.128" y1="-3.556" x2="7.112" y2="-3.556" width="0.254" layer="94"/>
<wire x1="8.128" y1="-3.556" x2="7.62" y2="-5.08" width="0.254" layer="94"/>
<text x="16.51" y="1.27" size="1.778" layer="95" align="center-left">&gt;NAME</text>
<text x="16.51" y="-1.27" size="1.778" layer="96" align="center-left">&gt;VALUE</text>
<pin name="1" x="0" y="0" visible="pad" length="short"/>
<pin name="2" x="0" y="-5.08" visible="pad" length="short"/>
<pin name="3" x="0" y="-2.54" visible="pad" length="short"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="C3216X6S1V106K160AC" urn="urn:adsk.eagle:component:27935316/1" prefix="C" library_version="1">
<description>&lt;b&gt;Multilayer Ceramic Capacitors MLCC - SMD/SMT 1206 35V 10uF X6S 10% T: 1.6mm&lt;/b&gt;&lt;p&gt;
Source: &lt;a href="https://product.tdk.com/info/en/catalog/datasheets/mlcc_commercial_midvoltage_en.pdf"&gt; Datasheet &lt;/a&gt;</description>
<gates>
<gate name="G$1" symbol="C3216X6S1V106K160AC" x="0" y="0"/>
</gates>
<devices>
<device name="" package="CAPC3216X180N">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27935305/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="DESCRIPTION" value="Multilayer Ceramic Capacitors MLCC - SMD/SMT 1206 35V 10uF X6S 10% T: 1.6mm" constant="no"/>
<attribute name="HEIGHT" value="1.8mm" constant="no"/>
<attribute name="MANUFACTURER_NAME" value="TDK" constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="C3216X6S1V106K160AC" constant="no"/>
<attribute name="MOUSER_PART_NUMBER" value="810-C3216X6S1V106K6A" constant="no"/>
<attribute name="MOUSER_PRICE-STOCK" value="https://www.mouser.co.uk/ProductDetail/TDK/C3216X6S1V106K160AC?qs=xLDY6iXSiQbqLIcRZVjJ3A%3D%3D" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="C0805C105K4RACTU" urn="urn:adsk.eagle:component:27935317/1" prefix="C" library_version="1">
<description>&lt;b&gt;1uF Ceramic Multilayer Capacitor, 16V&lt;/b&gt;&lt;p&gt;
Source: &lt;a href="http://www.kemet.com/Lists/ProductCatalog/Attachments/53/KEM_C1002_X7R_SMD.pdf"&gt; Datasheet &lt;/a&gt;</description>
<gates>
<gate name="G$1" symbol="C0805C105K4RACTU" x="0" y="0"/>
</gates>
<devices>
<device name="" package="CAPC2012X100N">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27935306/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="DESCRIPTION" value="1uF Ceramic Multilayer Capacitor, 16V" constant="no"/>
<attribute name="HEIGHT" value="1mm" constant="no"/>
<attribute name="MANUFACTURER_NAME" value="Kemet" constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="C0805C105K4RACTU" constant="no"/>
<attribute name="MOUSER_PART_NUMBER" value="80-C0805C105K4R" constant="no"/>
<attribute name="MOUSER_PRICE-STOCK" value="https://www.mouser.co.uk/ProductDetail/KEMET/C0805C105K4RACTU?qs=yrVqjCObULOefkidH6lLLQ%3D%3D" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="CC0805KRX7R9BB103" urn="urn:adsk.eagle:component:27935318/1" prefix="C" library_version="1">
<description>&lt;b&gt;0805 X7R ceramic cap,10nF 50V Phycomp 10nF Multilayer Ceramic Capacitor (MLCC) 50 V dc +/-10% X7R dielectric Standard max op. temp. +125C&lt;/b&gt;&lt;p&gt;
Source: &lt;a href=""&gt; Datasheet &lt;/a&gt;</description>
<gates>
<gate name="G$1" symbol="CC0805KRX7R9BB103" x="0" y="0"/>
</gates>
<devices>
<device name="" package="CAPC2012X135N">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27935307/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="DESCRIPTION" value="0805 X7R ceramic cap,10nF 50V Phycomp 10nF Multilayer Ceramic Capacitor (MLCC) 50 V dc +/-10% X7R dielectric Standard max op. temp. +125C" constant="no"/>
<attribute name="HEIGHT" value="1.35mm" constant="no"/>
<attribute name="MANUFACTURER_NAME" value="YAGEO (PHYCOMP)" constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="CC0805KRX7R9BB103" constant="no"/>
<attribute name="MOUSER_PART_NUMBER" value="603-CC805KRX7R9BB103" constant="no"/>
<attribute name="MOUSER_PRICE-STOCK" value="https://www.mouser.co.uk/ProductDetail/Yageo/CC0805KRX7R9BB103?qs=AgBp2OyFlx%252BOmOw2rEcWJw%3D%3D" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="B540C-13-F" urn="urn:adsk.eagle:component:27935315/1" prefix="D" library_version="1">
<description>&lt;b&gt;Diodes Inc B540C-13-F, SMT Schottky Diode, 40V 5A, 2-Pin DO-214AB&lt;/b&gt;&lt;p&gt;
Source: &lt;a href="https://componentsearchengine.com/Datasheets/2/B540C-13-F.pdf"&gt; Datasheet &lt;/a&gt;</description>
<gates>
<gate name="G$1" symbol="B540C-13-F" x="0" y="0"/>
</gates>
<devices>
<device name="" package="DIOM7959X250N">
<connects>
<connect gate="G$1" pin="A" pad="2"/>
<connect gate="G$1" pin="K" pad="1"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27935304/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="DESCRIPTION" value="Diodes Inc B540C-13-F, SMT Schottky Diode, 40V 5A, 2-Pin DO-214AB" constant="no"/>
<attribute name="HEIGHT" value="2.5mm" constant="no"/>
<attribute name="MANUFACTURER_NAME" value="Diodes Inc." constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="B540C-13-F" constant="no"/>
<attribute name="MOUSER_PART_NUMBER" value="621-B540C-F" constant="no"/>
<attribute name="MOUSER_PRICE-STOCK" value="https://www.mouser.co.uk/ProductDetail/Diodes-Incorporated/B540C-13-F?qs=v2dnQLbuoRZXHN%2FK4ft5%252Bg%3D%3D" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="SDR1307-4R7ML" urn="urn:adsk.eagle:component:27935320/1" prefix="L" library_version="1">
<description>&lt;b&gt;Fixed Inductors 4.7uH 20% SMD 1307&lt;/b&gt;&lt;p&gt;
Source: &lt;a href="https://www.bourns.com/pdfs/SDR1307.pdf"&gt; Datasheet &lt;/a&gt;</description>
<gates>
<gate name="G$1" symbol="SDR1307-4R7ML" x="0" y="0"/>
</gates>
<devices>
<device name="" package="SDR1307-220ML">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27935309/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="DESCRIPTION" value="Fixed Inductors 4.7uH 20% SMD 1307" constant="no"/>
<attribute name="HEIGHT" value="mm" constant="no"/>
<attribute name="MANUFACTURER_NAME" value="Bourns" constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="SDR1307-4R7ML" constant="no"/>
<attribute name="MOUSER_PART_NUMBER" value="652-SDR1307-4R7ML" constant="no"/>
<attribute name="MOUSER_PRICE-STOCK" value="https://www.mouser.co.uk/ProductDetail/Bourns/SDR1307-4R7ML?qs=uD%2FoUDWqfvTph9Rfuyszgg%3D%3D" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="TB006-508-02BE" urn="urn:adsk.eagle:component:27935321/1" prefix="J" library_version="1">
<description>&lt;b&gt;Fixed Terminal Blocks screw type, 5.08 , horizontal, 2 poles, CUI Blue, slotted screw, PCB mount&lt;/b&gt;&lt;p&gt;
Source: &lt;a href=""&gt; Datasheet &lt;/a&gt;</description>
<gates>
<gate name="G$1" symbol="TB006-508-02BE" x="0" y="0"/>
</gates>
<devices>
<device name="" package="TB00650802BE">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27935310/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="DESCRIPTION" value="Fixed Terminal Blocks screw type, 5.08 , horizontal, 2 poles, CUI Blue, slotted screw, PCB mount" constant="no"/>
<attribute name="HEIGHT" value="10.4mm" constant="no"/>
<attribute name="MANUFACTURER_NAME" value="CUI Inc." constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="TB006-508-02BE" constant="no"/>
<attribute name="MOUSER_PART_NUMBER" value="490-TB006-508-02BE" constant="no"/>
<attribute name="MOUSER_PRICE-STOCK" value="https://www.mouser.co.uk/ProductDetail/CUI-Devices/TB006-508-02BE?qs=vLWxofP3U2wEdOVV%2FaT04w%3D%3D" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="16SVPE180M" urn="urn:adsk.eagle:component:27935319/1" prefix="C" library_version="1">
<description>&lt;b&gt;Panasonic Aluminium Polymer Capacitor 180uF 16V dc 6.3mm C10 OS-CON Series, Surface Mount Polymer, +/-20% 6.3 x 9.9mm&lt;/b&gt;&lt;p&gt;
Source: &lt;a href="https://whttps://industrial.panasonic.com/cdbs/www-data/pdf/AAB8000/AAB8000C179.pdfww.arrow.com/en/products/16svpe180m/panasonic"&gt; Datasheet &lt;/a&gt;</description>
<gates>
<gate name="G$1" symbol="16SVPE180M" x="0" y="0"/>
</gates>
<devices>
<device name="" package="16SVPE180M">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27935308/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="DESCRIPTION" value="Panasonic Aluminium Polymer Capacitor 180uF 16V dc 6.3mm C10 OS-CON Series, Surface Mount Polymer, +/-20% 6.3 x 9.9mm" constant="no"/>
<attribute name="HEIGHT" value="10mm" constant="no"/>
<attribute name="MANUFACTURER_NAME" value="Panasonic" constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="16SVPE180M" constant="no"/>
<attribute name="MOUSER_PART_NUMBER" value="667-16SVPE180M" constant="no"/>
<attribute name="MOUSER_PRICE-STOCK" value="https://www.mouser.co.uk/ProductDetail/Panasonic/16SVPE180M?qs=OE1iw1LrrPH8IiQtRMzKQA%3D%3D" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="CON-SOCJ-2155" urn="urn:adsk.eagle:component:27935311/1" prefix="J" library_version="1">
<description>&lt;b&gt;DC Power Connectors Power Jack/Connector 2.1mm x 5.5mm&lt;/b&gt;&lt;p&gt;
Source: &lt;a href="http://www.produktinfo.conrad.com/datenblaetter/1500000-1599999/001582350-da-01-en-DC_EINBAUBUCHSE__SCHALTER_GESCHLOSSEN.pdf"&gt; Datasheet &lt;/a&gt;</description>
<gates>
<gate name="G$1" symbol="CON-SOCJ-2155" x="0" y="0"/>
</gates>
<devices>
<device name="" package="CONSOCJ2155">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27935300/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="DESCRIPTION" value="DC Power Connectors Power Jack/Connector 2.1mm x 5.5mm" constant="no"/>
<attribute name="HEIGHT" value="11mm" constant="no"/>
<attribute name="MANUFACTURER_NAME" value="Gravitech" constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="CON-SOCJ-2155" constant="no"/>
<attribute name="MOUSER_PART_NUMBER" value="992-CON-SOCJ-2155" constant="no"/>
<attribute name="MOUSER_PRICE-STOCK" value="https://www.mouser.co.uk/ProductDetail/Gravitech/CON-SOCJ-2155/?qs=fkzBJ5HM%252BdCcpvFQyQZHtA%3D%3D" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="supply1" urn="urn:adsk.eagle:library:371">
<description>&lt;b&gt;Supply Symbols&lt;/b&gt;&lt;p&gt;
 GND, VCC, 0V, +5V, -5V, etc.&lt;p&gt;
 Please keep in mind, that these devices are necessary for the
 automatic wiring of the supply signals.&lt;p&gt;
 The pin name defined in the symbol is identical to the net which is to be wired automatically.&lt;p&gt;
 In this library the device names are the same as the pin names of the symbols, therefore the correct signal names appear next to the supply symbols in the schematic.&lt;p&gt;
 &lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="GND" urn="urn:adsk.eagle:symbol:26925/1" library_version="1">
<wire x1="-1.905" y1="0" x2="1.905" y2="0" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96">&gt;VALUE</text>
<pin name="GND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="GND" urn="urn:adsk.eagle:component:26954/1" prefix="GND" library_version="1">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="GND" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="8SS1022-Z">
<description>&lt;Slide Switches SPDT, ON-OFF-ON, slide, straight PC terminals, 6A @ 125V AC&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by SamacSys&lt;/author&gt;</description>
<packages>
<package name="8SS1022Z">
<description>&lt;b&gt;8SS1022-Z-1&lt;/b&gt;&lt;br&gt;
</description>
<pad name="1" x="0" y="0" drill="1.6" diameter="2.4"/>
<pad name="2" x="0" y="-4.4" drill="1.6" diameter="2.4"/>
<pad name="3" x="0" y="-8.8" drill="1.6" diameter="2.4"/>
<text x="0" y="-4.4" size="1.27" layer="25" align="center">&gt;NAME</text>
<text x="0" y="-4.4" size="1.27" layer="27" align="center">&gt;VALUE</text>
<wire x1="-3.95" y1="-10.9" x2="3.95" y2="-10.9" width="0.1" layer="51"/>
<wire x1="3.95" y1="-10.9" x2="3.95" y2="2.1" width="0.1" layer="51"/>
<wire x1="3.95" y1="2.1" x2="-3.95" y2="2.1" width="0.1" layer="51"/>
<wire x1="-3.95" y1="2.1" x2="-3.95" y2="-10.9" width="0.1" layer="51"/>
<wire x1="-3.95" y1="2.1" x2="3.95" y2="2.1" width="0.2" layer="21"/>
<wire x1="3.95" y1="2.1" x2="3.95" y2="-10.9" width="0.2" layer="21"/>
<wire x1="3.95" y1="-10.9" x2="-3.95" y2="-10.9" width="0.2" layer="21"/>
<wire x1="-3.95" y1="-10.9" x2="-3.95" y2="2.1" width="0.2" layer="21"/>
<wire x1="-4.95" y1="3.1" x2="4.95" y2="3.1" width="0.1" layer="51"/>
<wire x1="4.95" y1="3.1" x2="4.95" y2="-11.9" width="0.1" layer="51"/>
<wire x1="4.95" y1="-11.9" x2="-4.95" y2="-11.9" width="0.1" layer="51"/>
<wire x1="-4.95" y1="-11.9" x2="-4.95" y2="3.1" width="0.1" layer="51"/>
<wire x1="-4.5" y1="0" x2="-4.5" y2="0" width="0.2" layer="21"/>
<wire x1="-4.5" y1="0" x2="-4.4" y2="0" width="0.2" layer="21" curve="180"/>
<wire x1="-4.4" y1="0" x2="-4.4" y2="0" width="0.2" layer="21"/>
<wire x1="-4.4" y1="0" x2="-4.5" y2="0" width="0.2" layer="21" curve="180"/>
<wire x1="-4.5" y1="0" x2="-4.5" y2="0" width="0.2" layer="21"/>
<wire x1="-4.5" y1="0" x2="-4.4" y2="0" width="0.2" layer="21" curve="180"/>
</package>
</packages>
<symbols>
<symbol name="8SS1022-Z">
<wire x1="5.08" y1="2.54" x2="15.24" y2="2.54" width="0.254" layer="94"/>
<wire x1="15.24" y1="-7.62" x2="15.24" y2="2.54" width="0.254" layer="94"/>
<wire x1="15.24" y1="-7.62" x2="5.08" y2="-7.62" width="0.254" layer="94"/>
<wire x1="5.08" y1="2.54" x2="5.08" y2="-7.62" width="0.254" layer="94"/>
<text x="16.51" y="7.62" size="1.778" layer="95" align="center-left">&gt;NAME</text>
<text x="16.51" y="5.08" size="1.778" layer="96" align="center-left">&gt;VALUE</text>
<pin name="1" x="0" y="0" length="middle"/>
<pin name="2" x="0" y="-2.54" length="middle"/>
<pin name="3" x="0" y="-5.08" length="middle"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="8SS1022-Z" prefix="S">
<description>&lt;b&gt;Slide Switches SPDT, ON-OFF-ON, slide, straight PC terminals, 6A @ 125V AC&lt;/b&gt;&lt;p&gt;
Source: &lt;a href="https://componentsearchengine.com/Datasheets/2/8SS1022-Z.pdf"&gt; Datasheet &lt;/a&gt;</description>
<gates>
<gate name="G$1" symbol="8SS1022-Z" x="0" y="0"/>
</gates>
<devices>
<device name="" package="8SS1022Z">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
</connects>
<technologies>
<technology name="">
<attribute name="DESCRIPTION" value="Slide Switches SPDT, ON-OFF-ON, slide, straight PC terminals, 6A @ 125V AC" constant="no"/>
<attribute name="HEIGHT" value="14.85mm" constant="no"/>
<attribute name="MANUFACTURER_NAME" value="NIDEC COPAL" constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="8SS1022-Z" constant="no"/>
<attribute name="MOUSER_PART_NUMBER" value="229-8SS1022-Z" constant="no"/>
<attribute name="MOUSER_PRICE-STOCK" value="https://www.mouser.co.uk/ProductDetail/Nidec-Copal/8SS1022-Z?qs=XeJtXLiO41S0FkmrxT6eNQ%3D%3D" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="frames" urn="urn:adsk.eagle:library:229">
<description>&lt;b&gt;Frames for Sheet and Layout&lt;/b&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="DINA4_L" urn="urn:adsk.eagle:symbol:13867/1" library_version="1">
<frame x1="0" y1="0" x2="264.16" y2="180.34" columns="4" rows="4" layer="94" border-left="no" border-top="no" border-right="no" border-bottom="no"/>
</symbol>
<symbol name="DOCFIELD" urn="urn:adsk.eagle:symbol:13864/1" library_version="1">
<wire x1="0" y1="0" x2="71.12" y2="0" width="0.1016" layer="94"/>
<wire x1="101.6" y1="15.24" x2="87.63" y2="15.24" width="0.1016" layer="94"/>
<wire x1="0" y1="0" x2="0" y2="5.08" width="0.1016" layer="94"/>
<wire x1="0" y1="5.08" x2="71.12" y2="5.08" width="0.1016" layer="94"/>
<wire x1="0" y1="5.08" x2="0" y2="15.24" width="0.1016" layer="94"/>
<wire x1="101.6" y1="15.24" x2="101.6" y2="5.08" width="0.1016" layer="94"/>
<wire x1="71.12" y1="5.08" x2="71.12" y2="0" width="0.1016" layer="94"/>
<wire x1="71.12" y1="5.08" x2="87.63" y2="5.08" width="0.1016" layer="94"/>
<wire x1="71.12" y1="0" x2="101.6" y2="0" width="0.1016" layer="94"/>
<wire x1="87.63" y1="15.24" x2="87.63" y2="5.08" width="0.1016" layer="94"/>
<wire x1="87.63" y1="15.24" x2="0" y2="15.24" width="0.1016" layer="94"/>
<wire x1="87.63" y1="5.08" x2="101.6" y2="5.08" width="0.1016" layer="94"/>
<wire x1="101.6" y1="5.08" x2="101.6" y2="0" width="0.1016" layer="94"/>
<wire x1="0" y1="15.24" x2="0" y2="22.86" width="0.1016" layer="94"/>
<wire x1="101.6" y1="35.56" x2="0" y2="35.56" width="0.1016" layer="94"/>
<wire x1="101.6" y1="35.56" x2="101.6" y2="22.86" width="0.1016" layer="94"/>
<wire x1="0" y1="22.86" x2="101.6" y2="22.86" width="0.1016" layer="94"/>
<wire x1="0" y1="22.86" x2="0" y2="35.56" width="0.1016" layer="94"/>
<wire x1="101.6" y1="22.86" x2="101.6" y2="15.24" width="0.1016" layer="94"/>
<text x="1.27" y="1.27" size="2.54" layer="94">Date:</text>
<text x="12.7" y="1.27" size="2.54" layer="94">&gt;LAST_DATE_TIME</text>
<text x="72.39" y="1.27" size="2.54" layer="94">Sheet:</text>
<text x="86.36" y="1.27" size="2.54" layer="94">&gt;SHEET</text>
<text x="88.9" y="11.43" size="2.54" layer="94">REV:</text>
<text x="1.27" y="19.05" size="2.54" layer="94">TITLE:</text>
<text x="1.27" y="11.43" size="2.54" layer="94">Document Number:</text>
<text x="17.78" y="19.05" size="2.54" layer="94">&gt;DRAWING_NAME</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="DINA4_L" urn="urn:adsk.eagle:component:13919/1" prefix="FRAME" uservalue="yes" library_version="1">
<description>&lt;b&gt;FRAME&lt;/b&gt;&lt;p&gt;
DIN A4, landscape with extra doc field</description>
<gates>
<gate name="G$1" symbol="DINA4_L" x="0" y="0"/>
<gate name="G$2" symbol="DOCFIELD" x="162.56" y="0" addlevel="must"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="IC1" library="SamacSys_Parts" deviceset="LM22678TJ-5.0_NOPB" device=""/>
<part name="C1" library="SamacSys_Parts" library_urn="urn:adsk.eagle:library:27935277" deviceset="C3216X6S1V106K160AC" device="" package3d_urn="urn:adsk.eagle:package:27935305/1"/>
<part name="C2" library="SamacSys_Parts" library_urn="urn:adsk.eagle:library:27935277" deviceset="C3216X6S1V106K160AC" device="" package3d_urn="urn:adsk.eagle:package:27935305/1"/>
<part name="C4" library="SamacSys_Parts" library_urn="urn:adsk.eagle:library:27935277" deviceset="C0805C105K4RACTU" device="" package3d_urn="urn:adsk.eagle:package:27935306/1"/>
<part name="C5" library="SamacSys_Parts" library_urn="urn:adsk.eagle:library:27935277" deviceset="CC0805KRX7R9BB103" device="" package3d_urn="urn:adsk.eagle:package:27935307/1"/>
<part name="D1" library="SamacSys_Parts" library_urn="urn:adsk.eagle:library:27935277" deviceset="B540C-13-F" device="" package3d_urn="urn:adsk.eagle:package:27935304/1"/>
<part name="L1" library="SamacSys_Parts" library_urn="urn:adsk.eagle:library:27935277" deviceset="SDR1307-4R7ML" device="" package3d_urn="urn:adsk.eagle:package:27935309/1"/>
<part name="J1" library="SamacSys_Parts" library_urn="urn:adsk.eagle:library:27935277" deviceset="TB006-508-02BE" device="" package3d_urn="urn:adsk.eagle:package:27935310/1"/>
<part name="J3" library="SamacSys_Parts" library_urn="urn:adsk.eagle:library:27935277" deviceset="TB006-508-02BE" device="" package3d_urn="urn:adsk.eagle:package:27935310/1"/>
<part name="J4" library="SamacSys_Parts" library_urn="urn:adsk.eagle:library:27935277" deviceset="TB006-508-02BE" device="" package3d_urn="urn:adsk.eagle:package:27935310/1"/>
<part name="C3" library="SamacSys_Parts" library_urn="urn:adsk.eagle:library:27935277" deviceset="16SVPE180M" device="" package3d_urn="urn:adsk.eagle:package:27935308/1"/>
<part name="J5" library="SamacSys_Parts" library_urn="urn:adsk.eagle:library:27935277" deviceset="CON-SOCJ-2155" device="" package3d_urn="urn:adsk.eagle:package:27935300/1"/>
<part name="GND1" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND2" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND4" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND5" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="GND6" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="S1" library="8SS1022-Z" deviceset="8SS1022-Z" device=""/>
<part name="FRAME1" library="frames" library_urn="urn:adsk.eagle:library:229" deviceset="DINA4_L" device=""/>
</parts>
<sheets>
<sheet>
<plain>
<text x="101.6" y="10.16" size="3.048" layer="94">Author: Tristan Stotesbery</text>
<text x="190.5" y="-12.7" size="3.048" layer="94">A</text>
</plain>
<instances>
<instance part="IC1" gate="G$1" x="63.5" y="73.66" smashed="yes" rot="R90">
<attribute name="NAME" x="55.88" y="100.33" size="1.778" layer="95" rot="R90" align="center-left"/>
<attribute name="VALUE" x="58.42" y="100.33" size="1.778" layer="96" rot="R90" align="center-left"/>
</instance>
<instance part="C1" gate="G$1" x="40.64" y="55.88" smashed="yes" rot="R90">
<attribute name="NAME" x="34.29" y="64.77" size="1.778" layer="95" rot="R90" align="center-left"/>
<attribute name="VALUE" x="36.83" y="64.77" size="1.778" layer="96" rot="R90" align="center-left"/>
</instance>
<instance part="C2" gate="G$1" x="30.48" y="55.88" smashed="yes" rot="R90">
<attribute name="NAME" x="24.13" y="64.77" size="1.778" layer="95" rot="R90" align="center-left"/>
<attribute name="VALUE" x="26.67" y="64.77" size="1.778" layer="96" rot="R90" align="center-left"/>
</instance>
<instance part="C4" gate="G$1" x="50.8" y="55.88" smashed="yes" rot="R90">
<attribute name="NAME" x="44.45" y="64.77" size="1.778" layer="95" rot="R90" align="center-left"/>
<attribute name="VALUE" x="46.99" y="64.77" size="1.778" layer="96" rot="R90" align="center-left"/>
</instance>
<instance part="C5" gate="G$1" x="68.58" y="68.58" smashed="yes" rot="R270">
<attribute name="NAME" x="74.93" y="59.69" size="1.778" layer="95" rot="R270" align="center-left"/>
<attribute name="VALUE" x="72.39" y="59.69" size="1.778" layer="96" rot="R270" align="center-left"/>
</instance>
<instance part="D1" gate="G$1" x="63.5" y="50.8" smashed="yes" rot="R180">
<attribute name="NAME" x="52.07" y="45.72" size="1.778" layer="95" rot="R180" align="center-left"/>
<attribute name="VALUE" x="52.07" y="48.26" size="1.778" layer="96" rot="R180" align="center-left"/>
</instance>
<instance part="L1" gate="G$1" x="88.9" y="55.88" smashed="yes">
<attribute name="NAME" x="105.41" y="62.23" size="1.778" layer="95" align="center-left"/>
<attribute name="VALUE" x="105.41" y="59.69" size="1.778" layer="96" align="center-left"/>
</instance>
<instance part="J1" gate="G$1" x="7.62" y="68.58" smashed="yes" rot="R180">
<attribute name="NAME" x="-8.89" y="60.96" size="1.778" layer="95" rot="R180" align="center-left"/>
<attribute name="VALUE" x="-8.89" y="63.5" size="1.778" layer="96" rot="R180" align="center-left"/>
</instance>
<instance part="J3" gate="G$1" x="124.46" y="68.58" smashed="yes">
<attribute name="NAME" x="140.97" y="76.2" size="1.778" layer="95" align="center-left"/>
<attribute name="VALUE" x="140.97" y="73.66" size="1.778" layer="96" align="center-left"/>
</instance>
<instance part="J4" gate="G$1" x="124.46" y="58.42" smashed="yes">
<attribute name="NAME" x="140.97" y="66.04" size="1.778" layer="95" align="center-left"/>
<attribute name="VALUE" x="140.97" y="63.5" size="1.778" layer="96" align="center-left"/>
</instance>
<instance part="C3" gate="G$1" x="111.76" y="55.88" smashed="yes" rot="R270">
<attribute name="NAME" x="118.11" y="46.99" size="1.778" layer="95" rot="R270" align="center-left"/>
<attribute name="VALUE" x="115.57" y="46.99" size="1.778" layer="96" rot="R270" align="center-left"/>
</instance>
<instance part="J5" gate="G$1" x="5.08" y="88.9" smashed="yes" rot="R90">
<attribute name="NAME" x="3.81" y="105.41" size="1.778" layer="95" rot="R90" align="center-left"/>
<attribute name="VALUE" x="6.35" y="105.41" size="1.778" layer="96" rot="R90" align="center-left"/>
</instance>
<instance part="GND1" gate="1" x="121.92" y="50.8" smashed="yes">
<attribute name="VALUE" x="119.38" y="48.26" size="1.778" layer="96"/>
</instance>
<instance part="GND2" gate="1" x="111.76" y="40.64" smashed="yes">
<attribute name="VALUE" x="109.22" y="38.1" size="1.778" layer="96"/>
</instance>
<instance part="GND4" gate="1" x="81.28" y="106.68" smashed="yes">
<attribute name="VALUE" x="78.74" y="104.14" size="1.778" layer="96"/>
</instance>
<instance part="GND5" gate="1" x="78.74" y="60.96" smashed="yes">
<attribute name="VALUE" x="76.2" y="58.42" size="1.778" layer="96"/>
</instance>
<instance part="GND6" gate="1" x="22.86" y="43.18" smashed="yes">
<attribute name="VALUE" x="20.32" y="40.64" size="1.778" layer="96"/>
</instance>
<instance part="S1" gate="G$1" x="17.78" y="88.9" smashed="yes" rot="R90">
<attribute name="NAME" x="10.16" y="105.41" size="1.778" layer="95" rot="R90" align="center-left"/>
<attribute name="VALUE" x="12.7" y="105.41" size="1.778" layer="96" rot="R90" align="center-left"/>
</instance>
<instance part="FRAME1" gate="G$1" x="-63.5" y="-20.32" smashed="yes"/>
<instance part="FRAME1" gate="G$2" x="99.06" y="-20.32" smashed="yes">
<attribute name="LAST_DATE_TIME" x="111.76" y="-19.05" size="2.54" layer="94"/>
<attribute name="SHEET" x="185.42" y="-19.05" size="2.54" layer="94"/>
<attribute name="DRAWING_NAME" x="116.84" y="-1.27" size="2.54" layer="94"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="N$1" class="0">
<segment>
<pinref part="C2" gate="G$1" pin="2"/>
<wire x1="30.48" y1="71.12" x2="30.48" y2="68.58" width="0.1524" layer="91"/>
<pinref part="C1" gate="G$1" pin="2"/>
<wire x1="40.64" y1="68.58" x2="40.64" y2="71.12" width="0.1524" layer="91"/>
<wire x1="40.64" y1="71.12" x2="30.48" y2="71.12" width="0.1524" layer="91"/>
<wire x1="40.64" y1="71.12" x2="50.8" y2="71.12" width="0.1524" layer="91"/>
<junction x="40.64" y="71.12"/>
<pinref part="C4" gate="G$1" pin="2"/>
<wire x1="50.8" y1="71.12" x2="50.8" y2="68.58" width="0.1524" layer="91"/>
<pinref part="IC1" gate="G$1" pin="VIN"/>
<wire x1="66.04" y1="73.66" x2="66.04" y2="71.12" width="0.1524" layer="91"/>
<wire x1="66.04" y1="71.12" x2="50.8" y2="71.12" width="0.1524" layer="91"/>
<junction x="50.8" y="71.12"/>
<pinref part="S1" gate="G$1" pin="3"/>
<wire x1="22.86" y1="88.9" x2="22.86" y2="71.12" width="0.1524" layer="91"/>
<wire x1="22.86" y1="71.12" x2="30.48" y2="71.12" width="0.1524" layer="91"/>
<junction x="30.48" y="71.12"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="SW"/>
<wire x1="63.5" y1="73.66" x2="63.5" y2="55.88" width="0.1524" layer="91"/>
<pinref part="C5" gate="G$1" pin="2"/>
<wire x1="63.5" y1="55.88" x2="68.58" y2="55.88" width="0.1524" layer="91"/>
<pinref part="L1" gate="G$1" pin="1"/>
<wire x1="68.58" y1="55.88" x2="88.9" y2="55.88" width="0.1524" layer="91"/>
<junction x="68.58" y="55.88"/>
<pinref part="D1" gate="G$1" pin="K"/>
<wire x1="63.5" y1="50.8" x2="63.5" y2="55.88" width="0.1524" layer="91"/>
<junction x="63.5" y="55.88"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="C5" gate="G$1" pin="1"/>
<pinref part="IC1" gate="G$1" pin="BOOT"/>
<wire x1="68.58" y1="68.58" x2="68.58" y2="73.66" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="FB"/>
<wire x1="76.2" y1="73.66" x2="76.2" y2="68.58" width="0.1524" layer="91"/>
<wire x1="76.2" y1="68.58" x2="109.22" y2="68.58" width="0.1524" layer="91"/>
<pinref part="L1" gate="G$1" pin="2"/>
<wire x1="109.22" y1="68.58" x2="109.22" y2="55.88" width="0.1524" layer="91"/>
<pinref part="C3" gate="G$1" pin="1"/>
<wire x1="109.22" y1="55.88" x2="111.76" y2="55.88" width="0.1524" layer="91"/>
<junction x="109.22" y="55.88"/>
<pinref part="J3" gate="G$1" pin="1"/>
<wire x1="124.46" y1="68.58" x2="119.38" y2="68.58" width="0.1524" layer="91"/>
<junction x="109.22" y="68.58"/>
<pinref part="J4" gate="G$1" pin="1"/>
<wire x1="119.38" y1="68.58" x2="109.22" y2="68.58" width="0.1524" layer="91"/>
<wire x1="124.46" y1="58.42" x2="119.38" y2="58.42" width="0.1524" layer="91"/>
<wire x1="119.38" y1="58.42" x2="119.38" y2="68.58" width="0.1524" layer="91"/>
<junction x="119.38" y="68.58"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="C3" gate="G$1" pin="2"/>
<pinref part="GND2" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="J1" gate="G$1" pin="1"/>
<wire x1="7.62" y1="68.58" x2="7.62" y2="55.88" width="0.1524" layer="91"/>
<pinref part="C2" gate="G$1" pin="1"/>
<wire x1="7.62" y1="55.88" x2="10.16" y2="55.88" width="0.1524" layer="91"/>
<pinref part="C1" gate="G$1" pin="1"/>
<wire x1="10.16" y1="55.88" x2="22.86" y2="55.88" width="0.1524" layer="91"/>
<wire x1="22.86" y1="55.88" x2="30.48" y2="55.88" width="0.1524" layer="91"/>
<wire x1="30.48" y1="55.88" x2="40.64" y2="55.88" width="0.1524" layer="91"/>
<junction x="30.48" y="55.88"/>
<pinref part="C4" gate="G$1" pin="1"/>
<wire x1="40.64" y1="55.88" x2="48.26" y2="55.88" width="0.1524" layer="91"/>
<junction x="40.64" y="55.88"/>
<wire x1="48.26" y1="55.88" x2="50.8" y2="55.88" width="0.1524" layer="91"/>
<pinref part="GND6" gate="1" pin="GND"/>
<wire x1="22.86" y1="45.72" x2="22.86" y2="55.88" width="0.1524" layer="91"/>
<junction x="22.86" y="55.88"/>
<pinref part="D1" gate="G$1" pin="A"/>
<wire x1="48.26" y1="50.8" x2="48.26" y2="55.88" width="0.1524" layer="91"/>
<junction x="48.26" y="55.88"/>
<pinref part="J5" gate="G$1" pin="3"/>
<pinref part="J5" gate="G$1" pin="2"/>
<wire x1="7.62" y1="88.9" x2="10.16" y2="88.9" width="0.1524" layer="91"/>
<wire x1="10.16" y1="88.9" x2="10.16" y2="55.88" width="0.1524" layer="91"/>
<junction x="10.16" y="88.9"/>
<junction x="10.16" y="55.88"/>
</segment>
<segment>
<pinref part="GND5" gate="1" pin="GND"/>
<wire x1="78.74" y1="63.5" x2="78.74" y2="66.04" width="0.1524" layer="91"/>
<wire x1="78.74" y1="66.04" x2="71.12" y2="66.04" width="0.1524" layer="91"/>
<pinref part="IC1" gate="G$1" pin="GND_1"/>
<wire x1="71.12" y1="66.04" x2="71.12" y2="73.66" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC1" gate="G$1" pin="GND_2"/>
<pinref part="GND4" gate="1" pin="GND"/>
<wire x1="63.5" y1="104.14" x2="63.5" y2="109.22" width="0.1524" layer="91"/>
<wire x1="63.5" y1="109.22" x2="81.28" y2="109.22" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="J3" gate="G$1" pin="2"/>
<wire x1="124.46" y1="66.04" x2="121.92" y2="66.04" width="0.1524" layer="91"/>
<pinref part="GND1" gate="1" pin="GND"/>
<wire x1="121.92" y1="66.04" x2="121.92" y2="55.88" width="0.1524" layer="91"/>
<pinref part="J4" gate="G$1" pin="2"/>
<wire x1="121.92" y1="55.88" x2="121.92" y2="53.34" width="0.1524" layer="91"/>
<wire x1="124.46" y1="55.88" x2="121.92" y2="55.88" width="0.1524" layer="91"/>
<junction x="121.92" y="55.88"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="J1" gate="G$1" pin="2"/>
<wire x1="7.62" y1="71.12" x2="20.32" y2="71.12" width="0.1524" layer="91"/>
<pinref part="S1" gate="G$1" pin="2"/>
<wire x1="20.32" y1="71.12" x2="20.32" y2="88.9" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<pinref part="J5" gate="G$1" pin="1"/>
<wire x1="5.08" y1="88.9" x2="5.08" y2="83.82" width="0.1524" layer="91"/>
<wire x1="5.08" y1="83.82" x2="17.78" y2="83.82" width="0.1524" layer="91"/>
<pinref part="S1" gate="G$1" pin="1"/>
<wire x1="17.78" y1="83.82" x2="17.78" y2="88.9" width="0.1524" layer="91"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="8.2" severity="warning">
Since Version 8.2, EAGLE supports online libraries. The ids
of those online libraries will not be understood (or retained)
with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports URNs for individual library
assets (packages, symbols, and devices). The URNs of those assets
will not be understood (or retained) with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports the association of 3D packages
with devices in libraries, schematics, and board files. Those 3D
packages will not be understood (or retained) with this version.
</note>
</compatibility>
</eagle>
