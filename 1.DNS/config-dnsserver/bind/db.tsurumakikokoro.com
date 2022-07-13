;
; BIND data file for local loopback interface
;
$TTL	604800
@	IN	SOA	tsurumakikokoro.com. root.tsurumakikokoro.com. (
			      1		; Serial
			 604800		; Refresh
			  86400		; Retry
			2419200		; Expire
			 604800 )	; Negative Cache TTL
;
@	IN	NS	tsurumakikokoro.com.
@	IN	A	169.254.11.3
www	IN	A	169.254.11.3

